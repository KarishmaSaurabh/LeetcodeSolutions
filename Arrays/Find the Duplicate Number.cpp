//optimized--O(1) space
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int res=-1;
        for(int i=0;i<n;i++){
            int x=abs(nums[i]);
            if(nums[x]<0){
               res = x;
            }
             nums[x]=-nums[x];
        }
       return res;
    }
};

//brute force
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int n=nums.size();
       unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int ans;
        for(auto x:m){
            if(x.second>1){
              ans=x.first;
            }
        }
        return ans;
    }
};
