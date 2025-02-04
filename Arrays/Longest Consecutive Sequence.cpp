//O(n) approach
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        int res=1;
        for(auto x:s){
            if(s.find(x-1)==s.end()){
                  int currV=x;
                  int currL=1;
                  while(s.find(currV+1)!=s.end()){
                    currV++;
                    currL++;
                  }
                  res=max(res,currL);
            }
        }
        return res;
    }
};
