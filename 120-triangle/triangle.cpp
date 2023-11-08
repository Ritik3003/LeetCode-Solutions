class Solution {
public:
int solve(vector<vector<int>>&grid,vector<vector<int>>&dp, int i, int j, int n){
    if(i<0 || j<0 || i>=n || j>=grid[i].size()){
        return 1e9;
    }
    if(i==n-1){
        return grid[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int a=solve(grid,dp,i+1,j,n);
    int b=solve(grid,dp,i+1,j+1,n);
    return dp[i][j]=min(a,b)+grid[i][j];
}


    int minimumTotal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(grid,dp,0,0,n);
    }
};