//O(nlogn)
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> v;
        if(root==NULL){
            return v;
        }
        queue<pair<Node*,int>> q;
        map<int,int> m;
        q.push({root,0});
        while(!q.empty()){
            Node* temp=q.front().first;
            int d=q.front().second;
            q.pop();
            m[d]=temp->data;
            if(temp->left){
                q.push({temp->left,d-1});
            }
            if(temp->right){
                q.push({temp->right,d+1});
            }
        }
        for(auto x:m){
            v.push_back(x.second);
        }
        return v;
    }
};
