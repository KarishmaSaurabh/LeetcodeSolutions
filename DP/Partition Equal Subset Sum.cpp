//O(n*n)
class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int i,int sm,vector<int>& nums){
        if(sm==0){
            return true;
        }
        if(i>=nums.size() || sm<0){
            return false;
        }
        if(dp[i][sm]!=-1){
            return dp[i][sm];
        }
        if(nums[i]>sm){
            return dp[i][sm]=solve(i+1,sm,nums);
        }
        return dp[i][sm]=(solve(i+1,sm-nums[i],nums) || solve(i+1,sm,nums));
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sm=0;
        for(int i=0;i<n;i++){
            sm+=nums[i];
        }
        if(sm%2!=0){
            return false;
        }
        sm=sm/2;
        dp.resize(n+1,vector<int> (sm+1, -1));
        return solve(0,sm,nums);
    }
};
