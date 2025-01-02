class Solution {
  public:
    vector<vector<int>> v;
    void solve(Node* root,vector<int> &k){
        if(root==NULL){
            return;
        }
        k.push_back(root->data);
        if(root->left==NULL && root->right==NULL){
            v.push_back(k);
        }
        else{
           solve(root->left,k);
           solve(root->right,k); 
        }
        k.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        if(root==NULL){
            return v;
        }
        vector<int> k;
        solve(root,k);
        return v;
    }
};
