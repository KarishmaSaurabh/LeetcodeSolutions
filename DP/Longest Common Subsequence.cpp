//Recursive soln brute force -- exponential complexity

class Solution {
public:
    int solve(int i1,int i2,int n1,int n2,string text1, string text2){
        if(i1<0 || i2<0){
            return 0;
        }
        if(text1[i1]==text2[i2]){
            return 1+solve(i1-1,i2-1,n1,n2,text1,text2);
        }
        return max(solve(i1,i2-1,n1,n2,text1,text2),solve(i1-1,i2,n1,n2,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size(),n2=text2.size();
        return solve(n1-1,n2-1,n1,n2,text1,text2);
    }
};

//DP with memoization-- O(n1*n2)
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i1,int i2,int n1,int n2,string &text1, string &text2){
        if(i1<=0 || i2<=0){
            return 0;
        }
        if(dp[i1][i2]!=-1){
            return dp[i1][i2];
        }
        if(text1[i1-1]==text2[i2-1]){
            return dp[i1][i2]=1+solve(i1-1,i2-1,n1,n2,text1,text2);
        }
        return dp[i1][i2]=max(solve(i1,i2-1,n1,n2,text1,text2),solve(i1-1,i2,n1,n2,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size(),n2=text2.size();
        dp.resize(n1+1,vector<int> (n2+1,-1));
        return solve(n1,n2,n1,n2,text1,text2);
    }
};

//DP - bottom up approach--O(n1*n2)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size(),n2=text2.size();
        int dp[n1+1][n2+1];
        for(int i=0;i<n1+1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<n2+1;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<n1+1;i++){
            for(int j=1;j<n2+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n1][n2];
    }
};
