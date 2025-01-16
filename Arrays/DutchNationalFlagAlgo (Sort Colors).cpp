//in-place single traversal
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
       int l=0,m=0,h=n-1;
       while(m<=h){
        if(nums[m]==0){
           swap(nums[l],nums[m]);
           l++;
           m++;
        }
        else if(nums[m]==1){
           m++;
        }
        else{
            swap(nums[m],nums[h]);
            h--;
        }
       }
       return;
    }
};

//brute force
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(),a=0,b=0,c=0;
        for(int i=0;i<n;i++){
           if(nums[i]==0){
            a++;
           }
           else if(nums[i]==1){
            b++;
           }
           else{
            c++;
           }
        }
        int i=0;
        while(i<n && a>0){
            nums[i]=0;
            i++;
            a--;
        }
        while(i<n && b>0){
            nums[i]=1;
            i++;
            b--;
        }
        while(i<n && c>0){
            nums[i]=2;
            i++;
            c--;
        }
        return;
        
    }
};
