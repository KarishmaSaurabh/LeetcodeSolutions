class Solution {
public:
    bool check(TreeNode *root,long lb,long ub){
        if(root==NULL){
            return true;
        }
        if(root->val>=ub || root->val<=lb){
            return false;
        }
        return check(root->left,lb,root->val) && check(root->right,root->val,ub);
    }
    bool isValidBST(TreeNode* root) {
       long ub=LONG_MAX;
       long lb=LONG_MIN;
       return check(root,lb,ub);
    }
};
