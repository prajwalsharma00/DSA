int removeDuplicates(int* nums, int numsSize) {
    int k = 1;
    int temp = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != temp) {
            temp = nums[i];
            nums[k++] = temp;
        }
    }


    return k;
}
