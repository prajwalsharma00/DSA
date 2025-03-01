/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void depth(struct TreeNode* header,int currentDepth,int* maxDepth){
    if (header==NULL){
        return;

    }
    if (currentDepth > (*maxDepth)) {
        (*maxDepth) = currentDepth;
    }
    depth(header->left, currentDepth + 1, maxDepth);
    depth(header->right, currentDepth + 1, maxDepth);



}
void sumFinder(struct TreeNode *root,int *sum,int depth,int current){
    if (root==NULL){
        return;
    }
    if (current==depth){
        (*sum)+=root->val;
    }
    sumFinder(root->left, sum,depth,current+1);
    sumFinder(root->right, sum,depth,current+1);
    

}

int deepestLeavesSum(struct TreeNode* root) {
    int max_depth=0;
    depth(root,0,&max_depth);
    int sum=0;
    sumFinder(root,&sum,max_depth,0);
    return sum;

    
}
