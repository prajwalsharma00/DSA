int** mergeArrays(int** nums1, int nums1Size, int* nums1ColSize, int** nums2, int nums2Size, int* nums2ColSize, int* returnSize, int** returnColumnSizes) {
    int range=nums1Size+nums2Size;
    printf("%d ",nums2[1][0]);
    int** answer=(int**)malloc(sizeof(int*)*(range+1));
    for (int i=0;i<range;i++){
        answer[i]=(int*)malloc(sizeof(int)*2);
    }
     *returnColumnSizes = (int*)malloc(sizeof(int) * range);

    int index = 0;
    for (int i = 0; i < nums1Size; i++) {
        answer[index] = nums1[i];
        (*returnColumnSizes)[index] = 2;  // Each row has 2 columns
        index++;
    }
    for (int i=0;i<nums2Size;i++){
        int flag=0;
        for (int j=0;j<nums1Size;j++){
            if (answer[j][0]==nums2[i][0]){
                answer[j][1]+=nums2[i][1];
                flag=1;
                break;
            }
        }
        if (!flag){
            answer[index]=nums2[i];
            (*returnColumnSizes)[index] = 2;
            index++;
            
        }
        
    }

    for (int i=0;i<index-1;i++){
        for (int j=i;j<index;j++){
            if (answer[i][0]>answer[j][0]){
                int temp_id=answer[i][0];
                int temp_value=answer[i][1];
                answer[i][0]=answer[j][0];
                answer[i][1]=answer[j][1];
                answer[j][0]=temp_id;
                answer[j][1]=temp_value;
            }
        }

    }
    for (int i=0;i<index;i++){
        printf("Id : %d Vlaue %d \n",answer[i][0],answer[i][1]);
    }
    
    *returnSize = index;
    return answer;
    
}
