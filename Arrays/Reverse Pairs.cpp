//brute force
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                  if(nums[i]>2*(long long)nums[j]){
                    c++;
                  }
            }
        }
        return c;
    }
};
//optimized using merge sort
class Solution {
public:
    void merge(int l,int m,int r,vector<int> &nums,int &c){
        vector<int> t;
        int j=m+1;
        for(int i=l;i<=m;i++){
            while(j<=r && nums[i]>2*(long long)nums[j]){
                j++;
            }
            c=c+(j-(m+1));
        }
        int lt=l,rt=m+1;
        while(lt<=m && rt<=r){
            if(nums[lt]<=nums[rt]){
               t.push_back(nums[lt]); 
               lt++;
            }
            else{
                t.push_back(nums[rt]);
                rt++;
            }
        }
        while(lt<=m){
            t.push_back(nums[lt++]); 
        }
        while(rt<=r){
            t.push_back(nums[rt++]); 
        }
        int k=0;
        for(int i=l;i<=r;i++){
            nums[i]=t[k++];
        }
    }
    void mergeSort(int l,int r,vector<int> &nums,int &c){
        if(l>=r){
           return;
        }
        int m=(l+r)/2;
        mergeSort(l,m,nums,c);
        mergeSort(m+1,r,nums,c);
        merge(l,m,r,nums,c);
    }
    int reversePairs(vector<int>& nums) {
       int n=nums.size();
       int c=0;
       mergeSort(0,n-1,nums,c);
       return c;
    }
};
