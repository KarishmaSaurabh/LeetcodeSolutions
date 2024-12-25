//Brute force-- O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--){
            int x=0;
            for(int j=i+1;j<n;j++){
                if(nums[i]<nums[j]){
                    x=max(x,dp[j]);
                }
            }
          dp[i]=1+x;
        }
        int mx = *max_element(dp.begin(),dp.end());
        return mx;
        
    }
};

//DP with memoization -- O(n^2)
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int n, int prev,vector<int>& nums){
        if(i>=n){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int len=solve(i+1,n,prev,nums);
        if(prev==-1 || nums[i]>nums[prev]){
            len=max(len,1+solve(i+1,n,i,nums));
        }
        return dp[i][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,vector<int> (n+1,-1));
       return solve(0,n,-1,nums);
        
    }
};

//Binary Search ---O(nlogn)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> v;
        v.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>v.back()){
                v.push_back(nums[i]);
            }
            else{
              int k=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
                v[k]=nums[i];
            }
        }
        return v.size();
    }
};