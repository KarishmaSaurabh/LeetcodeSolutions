class Solution {
public:
    int solve(TreeNode* root,int &maxi){
        if(root==NULL){
            return 0;
        }
        int lt=max(0,solve(root->left,maxi));
        int rt=max(0,solve(root->right,maxi));
        maxi=max(maxi,lt+rt+root->val);
        return max(lt,rt)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int maxi=INT_MIN;
        solve(root,maxi); 
        return maxi;  
    }
};
