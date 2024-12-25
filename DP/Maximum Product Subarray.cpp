//brute force-- O(n^2)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int mp=INT_MIN;
        for(int i=0;i<n;i++){
            int p=1;
            for(int j=i;j<n;j++){
               p=p*nums[j];
               mp=max(mp,p);
            }
        }
        return mp;

    }
};

//O(n)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),mp=INT_MIN,pp=1,sp=1,ms=INT_MIN;
        for(int i=0;i<n;i++){
            if(pp==0){
                pp=1;
            }
            if(sp==0){
                sp=1;
            }
            pp=pp*nums[i];
            sp=sp*nums[n-i-1];
           mp=max(mp,pp);
           ms=max(ms,sp);
        }
        return max(mp,ms);
    }
};
