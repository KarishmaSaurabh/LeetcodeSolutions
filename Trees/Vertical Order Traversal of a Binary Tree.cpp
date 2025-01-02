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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        if(root==NULL){
            return v;
        }
        map<int,map<int,vector<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            int hd=q.front().second.first;
            TreeNode *temp=q.front().first;
            int l=q.front().second.second;
            q.pop();
            m[hd][l].push_back(temp->val);
            if(temp->left){
                q.push({temp->left,{hd-1,l+1}});
            }
            if(temp->right){
                q.push({temp->right,{hd+1,l+1}});
            }
        }
        for(auto x:m){
            vector<int> ans;
            for(auto p:x.second){
                sort(p.second.begin(),p.second.end());
                for(auto t:p.second){
                    ans.push_back(t);
                }
            }
            v.push_back(ans);
        }
        return v;
    }
};
