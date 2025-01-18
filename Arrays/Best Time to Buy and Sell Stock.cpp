//O(n^2) brute force
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        if(n==1){
            return 0;
        }
        int i=0,j=1;
        int maxv=0;
        while(i<n && j<n){
             if(prices[j]<prices[i]){
                i=j;
                j=j+1;
             }
             else{
               maxv=max(maxv,prices[j]-prices[i]);
               j++;
             }
        }
        return maxv;
    }
};
//dp- O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxP(n, 0);
        maxP[n-1] = prices[n-1];
        for(int i=n-2; i>=0; i--){
            maxP[i] = max(maxP[i+1], prices[i]); 
        }
        int maxProfit = 0;
        for(int i=0; i<n; i++){
            maxProfit = max(maxProfit, maxP[i] - prices[i]); 
        }
        return maxProfit;
    }
};
