class Solution {
public:

bool check(int i, int j, int n, int m){
    if(i<0 || j<0 || i>=n || j>=m){
        return false;
    }
    return true;
}

    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    count++;
                }else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int ans=-1;
        while(q.size()){
            ans++;
            int length=q.size();
            for(int i=0; i<length; i++){
                auto it=q.front();
                q.pop();
                int x=it.first;
                int y=it.second;
                vector<int> d={0,1,0,-1,0};
                for(int j=0; j<4; j++){
                    int new_x=d[j]+x;
                    int new_y=d[j+1]+y;
                    if(check(new_x,new_y,n,m) && grid[new_x][new_y]==1){
                        grid[new_x][new_y]=2;
                        q.push({new_x,new_y});
                        count--;
                    }
                }
            }
        }
        if(count){
            return -1;
        }
        if(ans==-1){
            return 0;
        }
        return ans;
    }
};