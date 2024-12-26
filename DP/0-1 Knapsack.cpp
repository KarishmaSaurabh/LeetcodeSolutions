brute force--exponential TC
class Solution {
  public:
    int solve(int i,int c,vector<int> &val, vector<int> &wt){
        if(i<=0 || c<=0){
            return 0;
        }
        if(wt[i-1]<=c){
            return max(val[i-1]+solve(i-1,c-wt[i-1],val,wt),solve(i-1,c,val,wt));
        }
        return solve(i-1,c,val,wt);
    }
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        return solve(n,capacity,val,wt);
        
    }
};

//memoization
class Solution {
  public:
    vector<vector<int>> dp;
    int solve(int i,int c,vector<int> &val, vector<int> &wt){
        if(i<=0 || c<=0){
            return 0;
        }
        if(dp[i][c]!=-1){
            return dp[i][c];
        }
        if(wt[i-1]<=c){
            return dp[i][c]=max(val[i-1]+solve(i-1,c-wt[i-1],val,wt),solve(i-1,c,val,wt));
        }
        return dp[i][c]=solve(i-1,c,val,wt);
    }
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        dp.resize(n+1,vector<int>(capacity+1,-1));
        return solve(n,capacity,val,wt);
        
    }
};

//bottom up dp
class Solution {
  public:
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        int n=val.size();
        int dp[n+1][capacity+1];
        for(int i=0;i<n+1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<capacity+1;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<capacity+1;j++){
                if(wt[i-1]<=j){
                    dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][capacity];
        
    }
};
