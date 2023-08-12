class Solution {
public:
int solve(vector<vector<int>>&grid, vector<vector<int>>&dp, int i, int j){
    if(i<0 || j<0 || grid[i][j]==1){
        return 0;
    }
    if(i==0 && j==0){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    return dp[i][j]=solve(grid,dp,i-1,j)+solve(grid,dp,i,j-1);
}

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(grid,dp,n-1,m-1);
    }
};