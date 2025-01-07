class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return;
        }
        if(root->left){
            flatten(root->left);
            TreeNode *rt=root->right;
            root->right=root->left;
            root->left=NULL;
            TreeNode *p=root->right;
            while(p->right!=NULL){
                p=p->right;
            }
            p->right=rt;
        }
         flatten(root->right);
         return;
    }
};
