class Solution {
  public:
    vector<int> v;
    void dfs(Node *root){
        if(root==NULL){
            return;
        }
        dfs(root->left);
        v.push_back(root->data);
        dfs(root->right);
    }
    int kthLargest(Node *root, int k) {
        dfs(root);
        int n=v.size();
        return v[n-k];
    }
};
