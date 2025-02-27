/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* newdigits=(int*)malloc(sizeof(int)*(digitsSize+1));
    int flag=1;
    int index=digitsSize;
    for (int i=(digitsSize-1);i>=0;i--){
        int value;
        if (flag==1){
            value=*(digits+i)+flag;
            printf("%d\n",value);
            flag=0;

        }else{
            value=*(digits+i);
            printf("%d \n",value);
        }
        if (value==10){
            flag=1;
            value=0;
        }
        *(newdigits+(i+1))=value;

    }
    printf("%d ---\n",newdigits[digitsSize]);
    if (flag==1){
        *newdigits=1;
        *returnSize=digitsSize+1;
        return newdigits;
        
    }
    *returnSize=digitsSize;
    return (newdigits+1);
    
}
