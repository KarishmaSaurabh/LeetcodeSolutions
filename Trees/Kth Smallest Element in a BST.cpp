class Solution {
public:
    vector<int> v;
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL){
            return 0;
        }
        inorder(root);
        return v[k-1];
    }
};


class Solution {
public:
    int c=0,res=INT_MIN;
    void inorder(TreeNode* root,int k){
        if(root==NULL){
            return;
        }
        inorder(root->left,k);
        c++;
        if(c==k){
            res=root->val;
            return;
        }
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL){
            return 0;
        }
        inorder(root,k);
        return res;
    }
};
