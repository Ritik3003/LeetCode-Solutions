class Solution {
public:
    int shortestPath(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        queue<vector<int>> q;
        q.push({0,0,0,k});
        while(q.size()){
            auto it=q.front();
            q.pop();
            int x=it[0];
            int y=it[1];
            int step=it[2];
            int remk=it[3];
            if(x<0 || y<0 || x>=n || y>=m){
                continue;
            }
            if(x==n-1 && y==m-1){
                return step;
            }
            if(mat[x][y]==1){
                if(remk==0){
                    continue;
                }else{
                    remk--;
                }
            }
            if(vis[x][y]!=-1 && vis[x][y]>=remk){
                continue;
            }
            vis[x][y]=remk;
            q.push({x+1,y,step+1,remk});
            q.push({x-1,y,step+1,remk});
            q.push({x,y+1,step+1,remk});
            q.push({x,y-1,step+1,remk});
        }
        return -1;
    }
};