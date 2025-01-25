class Solution {
  public:
    int merge(vector<int> &arr,int l,int m,int r){
        int n1=m-l+1,n2=r-m,res=0;
        vector<int> le(n1),ri(n2);
        for(int i=0;i<n1;i++){
            le[i]=arr[i+l];
        }
        for(int i=0;i<n2;i++){
            ri[i]=arr[m+1+i];
        }
        int i=0,j=0,k=l;
        while(i<n1 && j<n2){
            if(le[i]<=ri[j]){
                arr[k]=le[i];
                k++;
                i++;
            }
            else{
               arr[k++]=ri[j++];
               res+=(n1-i);
            }
        }
        while(i<n1){
            arr[k++]=le[i++];
        }
        while(j<n2){
            arr[k++]=ri[j++];
        }
        return res;
    }
    int invC(vector<int> &arr,int l,int r) {
        int res=0;
        if(l<r){
            int m=(l+r)/2;
            res+=invC(arr,l,m);
            res+=invC(arr,m+1,r);
            res=res+merge(arr,l,m,r);
        }
        return res;
    }
    int inversionCount(vector<int> &arr){
        int n=arr.size();
        return invC(arr,0,n-1);
    }
};
