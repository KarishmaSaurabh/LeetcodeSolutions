//better solution--giving tle
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>> st;
        for(int i=0;i<n;i++){
           set<int> s;
            for(int j=i+1;j<n;j++){
                int x=-(nums[i]+nums[j]);
                if(s.find(x)!=s.end()){
                    vector<int> p={nums[i],nums[j],x};
                    sort(p.begin(),p.end());
                    st.insert(p);
                }
                s.insert(nums[j]);
            }
        }
        vector<vector<int>> res(st.begin(),st.end());
        return res;
    }
};

//optimal approach--O(nlogn+n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1,k=n-1;
            while(j<k){
                int x=nums[i]+nums[j]+nums[k];
                if(x<0){
                    j++;
                }
                else if(x>0){
                    k--;
                }
                else{
                    vector<int> p={nums[i],nums[j],nums[k]};
                    v.push_back(p);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                    while(j<k && nums[k]==nums[k+1]){
                        k--;
                    }
                }
            }
        }
        return v;
    }
};
