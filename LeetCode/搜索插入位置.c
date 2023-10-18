//
// Created by 大妖怪 on 2023/10/18.
//
/**
* 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 必须使用时间复杂度为 O(log n) 的算法。
*/
int searchInsert(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2; // 防止 left + right 整形溢出

        if(nums[mid] == target) {
            return mid; // 目标值返回索引
        }else if (nums[mid] < target) {
            left = mid + 1; // 右半部分
        }else{
            right = mid - 1; // 左半部分
        }
    }

    return left; // 没有目标值返回插入位置
}
// 暴力遍历
int searchInsert(int* nums, int numsSize, int target){
    for(int i = 0; i < numsSize; i ++) {
        if (nums[i] >= target) return i;
    }
    return numsSize; // 没有目标值返回插入位置
}