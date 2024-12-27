//partition dp-->MCM
//memoization--tc=O(n^3)
class Solution {
  public:
    vector<vector<int>> dp;
    int solve(int i,int j,vector<int> &arr){
        if(i==j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mi=INT_MAX,p;
        for(int k=i;k<j;k++){
            p=arr[i-1]*arr[k]*arr[j]+solve(i,k,arr)+solve(k+1,j,arr);
            mi=min(mi,p);
        }
        return dp[i][j]=mi;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        dp.resize(n,vector<int> (n,-1));
        return solve(1,n-1,arr);
        
    }
};

//bottom-up--- O(n^3)
class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int> (n));
        for(int i=0;i<n;i++){
            dp[i][i]=0;
        }
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<n;j++){
                int mi=INT_MAX,p;
                for(int k=i;k<j;k++){
                   p=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                   mi=min(mi,p);  
                }
                dp[i][j]=mi;
            }
        }
        return dp[1][n-1];
        
    }
};
