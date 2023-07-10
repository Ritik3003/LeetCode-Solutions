class Solution {
public:

bool check(int i, int j, int n, int m){
    if(i<0 || j<0 || i>=n || j>=m){
        return false;
    }
    return true;
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        while(q.size()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int step=q.front().second;
            q.pop();
            dist[row][col]=step;
            int dx[5]={1,0,-1,0,1};
            for(int i=0; i<4; i++){
                if(check(row+dx[i],col+dx[i+1],n,m) && visited[row+dx[i]][col+dx[i+1]]==0){
                    q.push({{row+dx[i],col+dx[i+1]},step+1});
                    visited[dx[i]+row][dx[i+1]+col]=1;
                }
            }
        }
        return dist;
    }
};