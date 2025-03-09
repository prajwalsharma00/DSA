/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void node_size(struct TreeNode *root,int *value){
    if (!root){
        return;
    }
    (*value)++;
    node_size(root->left,value);
    node_size(root->right,value);
}
void list(struct TreeNode* root1,int* index,int *array){
    if (!root1){
        return ;
    }
    list(root1->left,index,array);
    array[(*index)++]=root1->val;
    list(root1->right,index,array);

}
int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize) {
    int aa=0,b=0;
    node_size(root1,&aa);
    node_size(root2,&b);
    int *first_list=malloc(sizeof(int)*aa);
    int *second_list=malloc(sizeof(int)*b);
    *returnSize=(aa+b);
    memset(first_list,-1,sizeof(int)*aa);
    memset(second_list,-1,sizeof(int)*b);
    int index=0;
    list(root1,&index,first_list);
    index=0;
    list(root2,&index,second_list);
    index=0;
    int *a=malloc(sizeof(int)*(*returnSize));
    int a_index=0;
    int b_index=0;
    while(a_index<aa && b_index<b){
        if (first_list[a_index]<second_list[b_index]){
            a[index++]=first_list[a_index++];


        }else{
            a[index++]=second_list[b_index++];
        }
    }
    if (a_index>=aa){
        for (int i=b_index;i<b;i++){
            a[index++]=second_list[i];
        }
    }
    if (b_index>=b){
        for (int i=a_index;i<aa;i++){
            a[index++]=first_list[i];
        }
    }


    free(first_list);
    free(second_list);
    return a;

}
