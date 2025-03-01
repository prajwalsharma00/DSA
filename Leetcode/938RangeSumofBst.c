int sum(struct TreeNode* root, int s,int low,int high){
    if (root==NULL){
        return s;
    }
    if (root->val>=low && root->val<=high){
        s=s+root->val;
    }
    s=sum(root->left,s,low,high);
    s=sum(root->right,s,low,high);
    return s;
}
int rangeSumBST(struct TreeNode* root, int low, int high) {
    int value=sum(root,0,low,high);

    return value;

    
}
