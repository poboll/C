/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *ret = NULL;
    int left = 0;
    int right = numbersSize - 1;
    *returnSize = 0;
    while(left < right) {
        if(numbers[left] + numbers[right] == target) {
            ret = (int *)malloc(sizeof(int) * 2);
            ret[0] = left + 1;
            ret[1] = right + 1;
            *returnSize = 2;
            return ret;
        }
        else if(numbers[left] + numbers[right] < target) {
            left ++;
        }
        else if(numbers[left] + numbers[right] > target) {
            right --;
        }
    }
    return NULL;
}