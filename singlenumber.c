#include<stdio.h>

int singlenumber(int *nums,int numsSize)
{
	for(int i=0; i < numsSize;i++)
	{
		int count = 0;
		for(int j=0;j<numsSize;j++)
		{
			if(nums[i] == nums[j])
			{
				count++;
			}
		}

		if(count == 1)
		{
			return nums[i];
		}
	}	
	return -1;
}

int singlenumber2(int *nums,int numSize)
{
	// 大神做法
	// 使用位运算
	// 异或运算，相同为0,不同为1
	int res = 0;
	for (int i=0;i < numSize;i++)
	{
		res = res ^ nums[i];
	}
	return res;
}


int main()
{
	int nums[7] = {2,2,1,1,3,3,6};
	int ans = singlenumber2(nums,7);
	printf("%d\n",ans);	
}
