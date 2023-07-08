class Solution {
public:
    int dfs(vector<vector<int>>&grid, int n, int m, int i, int j, int zero){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==-1){
            return 0;
        }
        if(grid[i][j]==2 ){
            if(zero==-1){
                return 1;
            }
            return 0;
        }
        grid[i][j]=-1;
        zero--;
        int a=0;
        a+=dfs(grid,n,m,i+1,j,zero);
        a+=dfs(grid,n,m,i,j+1,zero);
        a+=dfs(grid,n,m,i-1,j,zero);
        a+=dfs(grid,n,m,i,j-1,zero);
        grid[i][j]=0;
        zero++;
        return a;
    }
    
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int zero=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    zero++;
                }
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    ans+=dfs(grid,n,m,i,j,zero);
                }
            }
        }
        return ans;
    }
};