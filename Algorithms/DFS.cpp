void dfs(int i,vector<int> &vis,vector<int> adj[],vector<int> &res){
      vis[i]=1;
      res.push_back(i);
      for(auto x:adj[i]){
          if(!vis[x]) dfs(x,vis,adj,res);
      }
}
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> res;
        vector<int> vis(V, 0);
        for(int i=0;i<V;i++){
            if(!vis[i])
				dfs(i, vis, adj, res);
        }
        return res;
}
