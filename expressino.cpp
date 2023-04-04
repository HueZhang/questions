/*
*使用栈，求表达式的值
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 比较优先级
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int evaluate(string tokens) {
    int i;
    // 两个栈，操作符栈和数字栈
    stack<int> values;
    stack<char> ops;

    for (i = 0; i < tokens.length(); i++) {
        if (tokens[i] == ' ')
            continue;
        // 如果当前字符是括号就压入操作符栈
        else if (tokens[i] == '(') {
            ops.push(tokens[i]);
        }
        // 判断是否为数字
        else if (isdigit(tokens[i])) {
            int val = 0;

            // 循环取出当前数字，并赋值给val
            while (i < tokens.length() && isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                // 指针后移
                i++;
            }
            // 压入数字栈
            values.push(val);
            // 抵消for循环的++操作，否则跳过了一个符号
            i--;
        }
        // 遇到右括号就出栈
        else if (tokens[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();
                // 出栈两个数字和一个符号，执行操作
                values.push(applyOp(val1, val2, op));
            }

            if (!ops.empty())
                ops.pop();
        }
         else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])) {
                int val2 = values.top();
                values.pop();

                int val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            ops.push(tokens[i]);
        }
    }
     while (!ops.empty()) {
        int val2 = values.top();
        values.pop();

        int val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}
int main()
{
    cout << evaluate("10 + 2 * 6") << endl; // Output: 22
    cout << evaluate("100 * 2 + 12") << endl; // Output: 212
    cout << evaluate("100 * ( 2 + 12 )") << endl; // Output: 1400
    cout << evaluate("100 / ( 2 + 12 )") << endl; // Output: 8

    return 0;
}
