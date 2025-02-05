class Solution {
  public:
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
       int n=adj.size();
       vector<int> res;
       vector<int> vis(n,0);
       queue<int> q;
       q.push(0);
       vis[0]=1;
       while(!q.empty()){
           int x=q.front();
           q.pop();
           res.push_back(x);
           for(auto k:adj[x]){
               if(!vis[k]){
                   q.push(k);
                   vis[k]=1;
               }
           }
       }
       return res;
    }
};
