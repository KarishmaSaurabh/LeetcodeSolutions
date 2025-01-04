class Solution {
public:
    int dfs(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        return 1+max(dfs(root->left),dfs(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int lh=dfs(root->left);
        int rh=dfs(root->right);
        if(abs(lh-rh)>1){
            return false;
        }
        return (isBalanced(root->left) && isBalanced(root->right)); 
    }
};
