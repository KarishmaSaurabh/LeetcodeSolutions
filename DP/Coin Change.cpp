//O(2^n)
class Solution {
public:
    int solve(int i,int n,vector<int>& coins,int sm){
        if(i>=n || sm<0){
            return 1e9;
        }
        if(sm==0){
            return 0;
        }
        if(coins[i]>sm){
           return solve(i+1,n,coins,sm);
        }
        else{
           return min(1+solve(i,n,coins,sm-coins[i]),solve(i+1,n,coins,sm));
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int x=solve(0,n,coins,amount);
        return (x==1e9) ? -1 : x;
    }
};
//O(n*n)
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int n,vector<int>& coins,int sm){
        if(i>=n || sm<0){
            return 1e9;
        }
        if(sm==0){
            return 0;
        }
        if(dp[i][sm]!=-1){
            return dp[i][sm];
        }
        if(coins[i]>sm){
           return dp[i][sm]=solve(i+1,n,coins,sm);
        }
        else{
           return dp[i][sm]=min(1+solve(i,n,coins,sm-coins[i]),solve(i+1,n,coins,sm));
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp.resize(n,vector<int> (amount+1,-1));
        int x=solve(0,n,coins,amount);
        return (x==1e9) ? -1 : x;
    }
};
