#include <stdio.h>
#include <string.h>

int trans(char s[])
{
    int ans = 0;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] >= '0' && s[i] <= '9') {
            ans += (s[i] - '0') * (1 << (4 * (strlen(s) - i - 1)));
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            ans += (s[i] - 'A' + 10) * (1 << (4 * (strlen(s) - i - 1)));
        }
    }
    return ans;
}

int main() {
    char s[100];
    scanf("%s", s);
    int ans = trans(s);
    printf("%d\n", ans);
    return 0;
}
