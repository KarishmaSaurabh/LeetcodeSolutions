class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]=i;
        }
        for(int i=0;i<n;i++){
            int x=target-nums[i];
            if(m.find(x)!=m.end() && i!=m[x]){
                v.push_back(i);
                v.push_back(m[x]);
                return v;
            }
        }
        return v;
    }
};
