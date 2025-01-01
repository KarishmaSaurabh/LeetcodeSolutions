class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> v;
        if(root==NULL){
            return v;
        }
        map<int,int> m;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            Node *temp=q.front().first;
            int d=q.front().second;
            q.pop();
            if(m.find(d)==m.end()){
                m[d]=temp->data;
            }
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
