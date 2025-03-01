/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
**/
void sumofleaves(struct TreeNode* root,int sum,int target,int* flag){
    if(root==NULL){
        return;
    }
    if (root->left==NULL && root->right==NULL){
        sum+=root->val;
        if (target==sum){

            *flag=1;
        }
        return;

    }else{
        sum+=root->val;
        sumofleaves(root->left,sum,target,flag);
        sumofleaves(root->right,sum,target,flag);
    }
    return;
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root==NULL){
        return false;
    }
    
    int *flag=malloc(sizeof(*flag));
    *flag=0;
    sumofleaves(root,0,targetSum,flag);

    int value=*flag;
    free(flag);
    if(value){
        return true;
    }else{
        return false;
    }

    
}
