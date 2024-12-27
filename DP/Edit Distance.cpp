//brute force-- exponential complexity
class Solution {
public:
    int solve(int i,int j,string &word1, string &word2,int n1,int n2){
        if(i==0){
           return j;
        }
        if(j==0){
            return i;
        }
        if(word1[i-1]==word2[j-1]){
            return solve(i-1,j-1,word1,word2,n1,n2);
        }
        return min(1+solve(i,j-1,word1,word2,n1,n2),min(1+solve(i-1,j,word1,word2,n1,n2),1+solve(i-1,j-1,word1,word2,n1,n2)));
    }
    int minDistance(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        return solve(n1,n2,word1,word2,n1,n2);
    }
};

//dp memoization

class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,string &word1, string &word2,int n1,int n2){
        if(i==0){
           return j;
        }
        if(j==0){
            return i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i-1]==word2[j-1]){
            return solve(i-1,j-1,word1,word2,n1,n2);
        }
        return dp[i][j]=min(1+solve(i,j-1,word1,word2,n1,n2),min(1+solve(i-1,j,word1,word2,n1,n2),1+solve(i-1,j-1,word1,word2,n1,n2)));
    }
    int minDistance(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        dp.resize(n1+1,vector<int> (n2+1,-1));
        return solve(n1,n2,word1,word2,n1,n2);
    }
};

//bottom-up dp

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1));
        for(int i=0;i<n1+1;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<n2+1;i++){
            dp[0][i]=i;
        }
        for(int i=1;i<n1+1;i++){
            for(int j=1;j<n2+1;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min(1+dp[i][j-1],min(1+dp[i-1][j],1+dp[i-1][j-1]));
                }
            }
        }
        return dp[n1][n2];
    }
};
