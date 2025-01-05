class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root==NULL){
            return v;
        }
        queue<TreeNode*> q;
        q.push(root);
        int c=0;
        while(!q.empty()){
            int k=q.size();
            vector<int> p;
            while(k--){
              TreeNode *t=q.front();
              q.pop();
              p.push_back(t->val);
              if(t->left){
                q.push(t->left);
              }
              if(t->right){
                q.push(t->right);
              }
            }
            if(c%2!=0){
                reverse(p.begin(),p.end());
            }
            v.push_back(p);
            c++;
        }
        return v;
    }
};
