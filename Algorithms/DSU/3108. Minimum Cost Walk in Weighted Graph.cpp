class DSU{
   private:
      vector<int> parent,rank,weights;
   public:
      DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        weights.resize(n,-1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
      }
      int find(int x){
        if(x!=parent[x]){
             parent[x]=find(parent[x]);
        }
        return parent[x];
      }
      void unionf(int u,int v,int wt){
        int xx=find(u);
        int yy=find(v);
        if(rank[xx]<rank[yy]){
            swap(xx,yy);
        }
        parent[yy]=xx;
        weights[xx]=weights[yy]=weights[xx] & weights[yy] & wt;
        if(rank[xx]==rank[yy]){
            rank[xx]++;
        }
      }
      int minC(int u,int v){
        if(u==v){
            return 0;
        }
        if(find(u)!=find(v)){
            return -1;
        }
        int x=find(u);
        return weights[x];
      }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DSU d(n);
        for(auto x:edges){
            d.unionf(x[0],x[1],x[2]);
        }
        vector<int> v;
        for(auto x:query){
             v.push_back(d.minC(x[0],x[1]));
        }
        return v;
    }
};
