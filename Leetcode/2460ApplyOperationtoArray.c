/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void shiftzerotolast(int *nums,int numsSize){
    for (int i=0;i<numsSize-1;i++){
        for (int j=i+1;j<numsSize;j++){
            if (nums[i]==0){
                int temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
        }
    }

}
int* applyOperations(int* nums, int numsSize, int* returnSize) {
    *returnSize=numsSize;
    for (int i=0;i<numsSize-1;i++){
        if (nums[i]==nums[i+1]){
            nums[i]=nums[i]*2;
            nums[i+1]=0;

        }
    }
    shiftzerotolast(nums,numsSize);
    return nums;
    
}
