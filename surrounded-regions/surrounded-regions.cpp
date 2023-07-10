class Solution {
public:
void solveo(vector<vector <char>> &board, int n, int m, int i, int j){
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!='O'){
            return ;
        }
        board[i][j]='A';
        solveo(board,n,m,i+1,j);
        solveo(board,n,m,i,j+1);
        solveo(board,n,m,i-1,j);
        solveo(board,n,m,i,j-1);
    }

    void solve(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]=='O'){
                    solveo(grid,n,m,i,j);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='A'){
                    grid[i][j]='O';
                }else if(grid[i][j]=='O'){
                    grid[i][j]='X';
                }
            }
        }
    }
};