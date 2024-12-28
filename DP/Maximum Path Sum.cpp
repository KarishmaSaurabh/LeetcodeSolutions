//exponential complexity
class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid){
    if(i==0 && j==0){
        return grid[0][0];
    }
    if(i<0 || j<0){
       return 1e9;
    }
    return min(grid[i][j]+solve(i-1,j,grid), grid[i][j]+solve(i,j-1,grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        return solve(n-1,m-1,grid);  
    }
};
//dp on grids--O(n*m)
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int j,vector<vector<int>>& grid){
    if(i==0 && j==0){
        return grid[0][0];
    }
    if(i<0 || j<0){
       return 1e9;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    return dp[i][j]= min(grid[i][j]+solve(i-1,j,grid), grid[i][j]+solve(i,j-1,grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        dp.resize(n,vector<int> (m,-1));
        return solve(n-1,m-1,grid);  
    }
};
