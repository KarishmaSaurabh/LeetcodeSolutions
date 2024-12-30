//partition dp-- exponential complexity
class Solution {
public:
    bool solve(string s,unordered_set<string> &st){
        if(s.size()==0){
            return true;
        }
        for(int k=0;k<s.size();k++){
            if(st.find(s.substr(0,k+1))!=st.end() && solve(s.substr(k+1),st)){
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=wordDict.size();
        unordered_set<string> st;
        for(int i=0;i<n;i++){
            st.insert(wordDict[i]);
        }
        return solve(s,st);
    }
};

//optimized soln-- O(n^3)
class Solution {
public:
    vector<int> dp;
    bool solve(string s,int i,unordered_set<string> &st){
        if(i==s.size()){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int k=i;k<s.size();k++){
            if(st.find(s.substr(i,k+1-i))!=st.end() && solve(s,k+1,st)){
                return dp[i]=1;
            }
        }
        return dp[i]= 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=wordDict.size();
        unordered_set<string> st;
        dp.resize(s.size(),-1);
        for(int i=0;i<n;i++){
            st.insert(wordDict[i]);
        }
        return (solve(s,0,st)==1);
    }
};
