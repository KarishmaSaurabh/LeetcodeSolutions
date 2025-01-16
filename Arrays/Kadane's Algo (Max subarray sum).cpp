class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxs=INT_MIN,s=0;
        for(int i=0;i<n;i++){
            s=s+nums[i];
            if(s>maxs){
                maxs=s;
            }
            if(s<0){
                s=0;
            }

        }
        return maxs;
    }
};
