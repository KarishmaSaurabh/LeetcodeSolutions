/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode *curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                v.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode *k=curr->left;
                while(k->right!=NULL && k->right!=curr){
                    k=k->right;
                }
                if(k->right==NULL){
                   k->right=curr;
                   v.push_back(curr->val);
                   curr=curr->left;
                }
                else{
                   k->right=NULL;
                   curr=curr->right;
                }
            }
        }
        return v;
    }
};
