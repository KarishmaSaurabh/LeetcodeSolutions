//exponential
class Solution {
  public:
    int solve(int i,int p,int n,vector<int>& arr){
        if(i>=n){
            return 0;
        }
        if(p<arr[i]){
            return max(arr[i]+solve(i+1,arr[i],n,arr),solve(i+1,p,n,arr));
        }
        return solve(i+1,p,n,arr);
    }
    int maxSumIS(vector<int>& arr) {
        int n=arr.size();
        return solve(0,-1,n,arr);
    }
};

//optimized dp

class Solution {
  public:
  vector<vector<int>> dp;
    int solve(int i,int p,int n,vector<int>& arr){
        if(i>=n){
            return 0;
        }
        if(dp[i][p+1]!=-1){
            return dp[i][p+1];
        }
        if(p==-1 || arr[p]<arr[i]){
            return max(arr[i]+solve(i+1,i,n,arr),solve(i+1,p,n,arr));
        }
        return dp[i][p+1]=solve(i+1,p,n,arr);
    }
    int maxSumIS(vector<int>& arr) {
        int n=arr.size();
        dp.resize(n+1,vector<int> (n+1,-1));
        return solve(0,-1,n,arr);
    }
};
