int* sortedSquares(int* nums, int numsSize, int* returnSize){
    //返回的数组大小就是原数组大小
    *returnSize = numsSize;
    //创建两个指针，right指向数组最后一位元素，left指向数组第一位元素
    int right = numsSize - 1;
    int left = 0;

    //最后要返回的结果数组
    int* ans = (int*)malloc(sizeof(int) * numsSize);
    int index;
    for(index = numsSize - 1; index >= 0; index--) {
        //左指针指向元素的平方
        int lSquare = nums[left] * nums[left];
        //右指针指向元素的平方
        int rSquare = nums[right] * nums[right];
        //若左指针指向元素平方比右指针指向元素平方大，将左指针指向元素平方放入结果数组。左指针右移一位
        if(lSquare > rSquare) {
            ans[index] = lSquare;
            left++;
        } 
        //若右指针指向元素平方比左指针指向元素平方大，将右指针指向元素平方放入结果数组。右指针左移一位
        else {
            ans[index] = rSquare;
            right--;
        }
    }
    //返回结果数组
    return ans;
}