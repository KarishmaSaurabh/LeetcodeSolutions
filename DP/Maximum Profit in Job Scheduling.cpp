//O(nlogn)
class Solution {
public:
   vector<int> dp;
    int solve(int i,vector<vector<int>> &nums,int n,vector<int>& startTime){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ind=lower_bound(startTime.begin(),startTime.end(),nums[i][1])-startTime.begin();
        int dontp=solve(i+1,nums,n,startTime);
        int p=nums[i][2]+solve(ind,nums,n,startTime);
        int res=max(p,dontp);
        return dp[i]=res;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>> nums(n,vector<int> (3,0));
        for(int i=0;i<startTime.size();i++){
            nums[i][0]=startTime[i];
            nums[i][1]=endTime[i];
            nums[i][2]=profit[i];
        }
        dp.resize(n+1,-1);
        sort(nums.begin(),nums.end());
        sort(startTime.begin(),startTime.end());
        return solve(0,nums,n,startTime);
    }
};
