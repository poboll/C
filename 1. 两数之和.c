#include<stdio.h>
#include<malloc.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int i, j;
	int* result = (int*)malloc(sizeof(int)* 2);
	for (i = 0; i < numsSize - 1; i++)
	{
		for (j = i + 1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				result[0] = i;
				result[1] = j;
				*returnSize = 2;
				return result;
			}
		}
	}
	return 0;
}

int main()
{
	int nums[] = { 2, 5, 7, 15 };
	int target = 9;
	int numsSize = sizeof(nums) / sizeof(int);
	int* returnSize = (int*)malloc(sizeof(int)*numsSize);
	int* array = twoSum(nums, numsSize, target, returnSize);
	int i;
	for (i = 0; i < 2;i++)
	printf("%d ", array[i]);
	return 0;
}