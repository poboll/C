void moveZeroes(int* nums, int numsSize) {
	if (numsSize < 2) return;
	for (int i = 0, j = 0; i < numsSize; i++) {
		if (nums[i] != 0) {
			nums[j++] = nums[i];
		}
		if (i >= j) nums[i] = 0; //移动完就赋值为0
	}
	return;
}