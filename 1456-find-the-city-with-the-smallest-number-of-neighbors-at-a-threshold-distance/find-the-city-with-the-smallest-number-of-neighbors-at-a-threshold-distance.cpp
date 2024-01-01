class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thresold) {
        
        vector<vector<int>> grid(n,vector<int>(n,1e9));
        // vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(int i=0; i<edges.size(); i++){
            grid[edges[i][0]][edges[i][1]]=edges[i][2];
            grid[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i=0; i<n; i++){
            grid[i][i]=0;
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(grid[i][k]==1e9 || grid[k][j]==1e9){
                        continue;
                    }
                    grid[i][j]=min(grid[i][j],grid[i][k]+grid[k][j]);
                }
            }
        }
        int ans=0;
        int max=n;
        for(int i=0; i<n; i++){
            int count=0;
            for(int j=0; j<n; j++){
                if(grid[i][j]<=thresold){
                    count++;
                }
            }
            if(count<=max){
                max=count;
                ans=i;
            }
        }
        return ans;
    }
};