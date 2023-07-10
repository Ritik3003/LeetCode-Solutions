class Solution {
public:
void solve(vector<int> adj[],vector<int>&visited,int i){
    visited[i]=1;
    for(auto it: adj[i]){
        if(visited[it]==0){
            solve(adj,visited,it);
        }
    }
}

    int findCircleNum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(n,0);
        int ans=0;
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                ans++;
                solve(adj,visited,i);
            }
        }
        return ans;
    }
};