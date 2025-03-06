/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<string.h>

int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    int* returnarray=malloc(sizeof(*returnarray)*2);
    int size=gridSize*gridSize+1;
    int hashmap[size];
    memset(hashmap,-1,sizeof(hashmap));
    for (int i=0;i<gridSize;i++){
        for (int j=0;j<(*gridColSize);j++){
            if (hashmap[grid[i][j]]!=-1){
                returnarray[0]=hashmap[grid[i][j]];
            }else{
                hashmap[grid[i][j]]=grid[i][j];
            }
        }
    }
    for (int i=1;i<size;i++){
        if (hashmap[i]==-1){
            returnarray[1]=i;
        }
    }
    printf("%d\n",hashmap[3]);
    *returnSize=2;
    return returnarray;

    
}
