//mcm pattern
//memoization(giving tle)--O(n^3)
class Solution {
public: 
    vector<vector<int>> dp;
    int solve(int k,int n){
        if(n==0 || n==1){
            return n;
        }
        if(k==1){
            return n;
        }
        if(dp[k][n]!=-1){
            return dp[k][n];
        }
        int mini=INT_MAX;
        for(int p=1;p<=n;p++){
            int mo=1+max(solve(k-1,p-1),solve(k,n-p));
            mini=min(mini,mo);
        }
        return dp[k][n]=mini;
    }
    int superEggDrop(int k, int n) {
        dp.resize(k+1,vector<int> (n+1,-1));
        return solve(k,n);
    }
};
//Optimized code for memoization--O(n^2*logn)
class Solution {
public: 
    vector<vector<int>> dp;
    int solve(int k,int n){
        if(n==0 || n==1){
            return n;
        }
        if(k==1){
            return n;
        }
        if(dp[k][n]!=-1){
            return dp[k][n];
        }
        int mini=INT_MAX,l=1,r=n,mo=0;
        while(l<=r){
            int m=(l+r)/2;
            int down=solve(k-1,m-1);
            int up=solve(k,n-m);
            mo=1+max(down,up);
            if(down<up){
                l=m+1;
            }
            else{
                r=m-1;
            }
            mini=min(mini,mo);
        }
        return dp[k][n]=mini;
    }
    int superEggDrop(int k, int n) {
        dp.resize(k+1,vector<int> (n+1,-1));
        return solve(k,n);
    }
};
