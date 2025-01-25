class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      int n=nums.size();
      int c1=0,c2=0,cd1=-1,cd2=-1;
      for(int i=0;i<n;i++){
        if(cd1==nums[i]){
            c1++;
        }
        else if(cd2==nums[i]){
            c2++;
        }
        else if(c1==0){
            cd1=nums[i];
            c1=1;
        }
        else if(c2==0){
            cd2=nums[i];
            c2=1;
        }
        else{
            c1--;c2--;
        }
      }
     c1=0,c2=0;
      for(int i=0;i<n;i++){
        if(cd1==nums[i]){
            c1++;
        }
        else if(cd2==nums[i]){
            c2++;
        }
      }
      int mini=n/3+1;
      vector<int> res;
      if(c1>=mini){
        res.push_back(cd1);
      }
       if(c2>=mini){
        res.push_back(cd2);
      }
      return res;
        
    }
};
