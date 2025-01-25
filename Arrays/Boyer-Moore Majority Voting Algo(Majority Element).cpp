class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int can=-1,c=0;
        for(int i=0;i<n;i++){
             if(c==0){
                can=nums[i];
                c=1;
             }
             else if(nums[i]==can){
                c++;
             }
             else{
                c--;
             }
        }
        return can;

        
    }
};
