/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    int *smaller_value=(int*)malloc(sizeof(int*)*numsSize);
    int *bigger_value=(int*)malloc(sizeof(int*)*numsSize);
    int *pivot_value=(int*)malloc(sizeof(int*)*numsSize);
    int smaller_index=0;
    int bigger_index=0;
    int pivot_index=0;
    for (int i=0;i<numsSize;i++){
        if (nums[i]==pivot){
            pivot_value[pivot_index++]=nums[i];

        }else if (nums[i]>pivot){
            bigger_value[bigger_index++]=nums[i];
        }else{
            smaller_value[smaller_index++]=nums[i];
        }
    }
    for (int i=0;i<pivot_index;i++){
        smaller_value[smaller_index++]=pivot_value[i];
    }
    free(pivot_value);
    pivot_value=NULL;
    for (int i=0;i<bigger_index;i++){
        smaller_value[smaller_index++]=bigger_value[i];
    }
    *returnSize=smaller_index;
    free(bigger_value);
    bigger_value=NULL;
    return smaller_value;
}
