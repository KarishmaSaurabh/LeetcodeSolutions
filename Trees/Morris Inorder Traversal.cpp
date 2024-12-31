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
//tc=O(n), sc=O(1)
class Solution {
public:
    vector<int> v;
    vector<int> inorderTraversal(TreeNode* root) {
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
                    curr=curr->left;
                }
                else{
                    v.push_back(curr->val);
                    k->right=NULL;
                    curr=curr->right;
                }

            }
        }
        return v;
    }
};
