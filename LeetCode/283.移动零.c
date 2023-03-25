    int i = 0,j = 0;
    for(i = 0 ; i < numsSize; i++)
    {
        if(nums[i] != 0)
        {
            nums[j++] = nums[i];
        }
    }
    while(j < numsSize)
    {
        nums[j++] = 0;
    }