class Solution {
public:
int solve(vector<vector<int>>&dp, int n, int m, int i, int j){
    if(i>=n || j>=m || i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(i==n-1 && j==m-1){
        return 1;
    }
    int a=solve(dp,n,m,i+1,j);
    int b=solve(dp,n,m,i,j+1);
    return dp[i][j]=a+b;
}

    int uniquePaths(int n, int m) {
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(dp,n,m,0,0);
    }
};