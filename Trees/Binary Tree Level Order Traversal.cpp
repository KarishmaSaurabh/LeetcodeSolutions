class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root==NULL){
            return v;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int c=q.size();
            vector<int> p;
            while(c--){
                TreeNode *k=q.front();
                p.push_back(k->val);
            q.pop();
            if(k->left){
                q.push(k->left);
            }
            if(k->right){
                q.push(k->right);
            }
            }
           v.push_back(p);
        }
        return v;
    }
};
