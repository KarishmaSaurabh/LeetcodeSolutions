class Solution {
public:
    int dfs(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        return 1+max(dfs(root->left),dfs(root->right));
    }
    int maxDepth(TreeNode* root) {
       return dfs(root);  
    }
};
