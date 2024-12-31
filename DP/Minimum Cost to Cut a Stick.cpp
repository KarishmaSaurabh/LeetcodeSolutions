//partition dp
//TC-O(n^3) -- 2 changing parameters+additional loop
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,vector<int>& cuts){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int minc=INT_MAX;
        for(int k=i;k<=j;k++){
            int cost=cuts[j+1]-cuts[i-1]+solve(i,k-1,cuts)+solve(k+1,j,cuts);
            minc=min(minc,cost);
        }
        return dp[i][j]=minc;
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.push_back(0);
        dp.resize(c+2,vector<int> (c+2,-1));
        sort(cuts.begin(),cuts.end());
        return solve(1,c,cuts);
    }
};
