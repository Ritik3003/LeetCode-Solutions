class Solution {
public:
void solve(vector<vector<int>>&grid, int n, int m, int i, int j){
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1){
        return ;
    }
    grid[i][j]=0;
    solve(grid,n,m,i+1,j);
    solve(grid,n,m,i-1,j);
    solve(grid,n,m,i,j+1);
    solve(grid,n,m,i,j-1);
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((grid[i][j]==1) && (i==0 || j==0 || i==n-1 || j==m-1)){
                    solve(grid,n,m,i,j);
                }
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // cout<<grid[i][j]<<" ";
                if(grid[i][j]==1){
                    ans++;
                }
            }
            // cout<<"\n";
        }
        return ans;
    }
};