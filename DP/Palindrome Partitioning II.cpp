//partition dp--Memoization soln
//O(n^3)
class Solution {
public:
    vector<int> dp;
    bool isPalindrome(int i,int j,string &s){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    int solve(int i,int j,string &s){
        if(i>=j){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        if(isPalindrome(i,j,s)){
            return dp[i]=0;
        }
        int mini=INT_MAX;
        for(int k=i;k<=j;k++){
            if(isPalindrome(i,k,s)){
                mini=min(mini,1+solve(k+1,j,s));
            }
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        dp.resize(s.size()+1,-1);
        return solve(0,s.size()-1,s);
    }
};
