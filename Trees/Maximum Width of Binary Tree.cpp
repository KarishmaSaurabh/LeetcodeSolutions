class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int res=INT_MIN;
        while(!q.empty()){
            int c=q.size();
            int fr=q.front().second;
            int ba=q.back().second;
            res=max(res,ba-fr+1);
            while(c--){
                TreeNode *tmp=q.front().first;
                int i=q.front().second-fr;
                q.pop();
                if(tmp->left){
                    q.push({tmp->left,(long long)2*i});
                }
                if(tmp->right){
                    q.push({tmp->right,(long long)2*i+1});
                }
            }
        } 
        return res;
    }
};
