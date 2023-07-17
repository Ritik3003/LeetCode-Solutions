class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph(n,vector<int>(n,1e9));
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]][edges[i][1]]=edges[i][2];
            graph[edges[i][1]][edges[i][0]]=edges[i][2];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j){
                    graph[i][j]=0;
                }
            }
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(graph[i][k]==1e9 || graph[k][j]==1e9){
                        continue;
                    }
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                }
            }
        }
        int count=n;
        int city=-1;
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(graph[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=count){
                count=cnt;
                city=i;
            }
        }
        return city;

    }
};