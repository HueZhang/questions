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



int main()
{
	int nums[7] = {2,2,1,1,3,3,6};
	int ans = singlenumber(nums,7);
	printf("%d\n",ans);	
}
