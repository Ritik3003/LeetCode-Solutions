class Solution {
public:
void solve(vector<vector<char>>&grid, int n, int m, int i, int j){
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0'){
        return ;
    }
    grid[i][j]='0';
    solve(grid,n,m,i+1,j);
    solve(grid,n,m,i,j+1);
    solve(grid,n,m,i-1,j);
    solve(grid,n,m,i,j-1);
}

    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'){
                    ans++;
                    solve(grid,n,m,i,j);
                }
            }
        }
        return ans;
    }
};