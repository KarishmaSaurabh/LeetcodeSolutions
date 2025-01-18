class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
       int n=arr.size();
       int re;
       vector<int> v;
       for(int i=0;i<n;i++){
           int x=abs(arr[i])-1;
           if(arr[x]>0){
               arr[x]=-arr[x];
           }
           else{
               re=x+1;
           }
          
       }
       for(int i=0;i<n;i++){
           if(arr[i]>0){
               return {re,i+1};
           }
       }
       return {-1,-1};
    }
};
