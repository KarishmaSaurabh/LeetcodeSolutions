class Solution {
public:
    int dfs(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        return 1+max(dfs(root->left),dfs(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lf= dfs(root->left);
        int rt=dfs(root->right);
        int ld=diameterOfBinaryTree(root->left);
        int rd=diameterOfBinaryTree(root->right);
        return max(lf+rt,max(ld,rd));
    }
};
