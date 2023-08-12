class Solution {
public:
int solve(vector<vector<int>>&grid, int i, int j,int n, int m){
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0){
        return 0;
    }
    int temp=grid[i][j];
    grid[i][j]=0;
    int left=solve(grid,i-1,j,n,m);
    int right=solve(grid,i+1,j,n,m);
    int up=solve(grid,i,j-1,n,m);
    int down=solve(grid,i,j+1,n,m);
    grid[i][j]=temp;
    return max(left,max(right,max(up,down)))+temp;
}

    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0; i<n; i++){
            // vector<vector<int>> dp(n,vector<int>(m,-1));
            for(int j=0; j<m; j++){
                ans=max(ans,solve(grid,i,j,n,m));
            }
        }
        return ans;
    }
};