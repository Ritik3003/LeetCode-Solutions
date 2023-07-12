class Solution {
public:
void solve(vector<int> adj[], vector<int>&visited, vector<int>&path_visited, bool&check, int i){
    visited[i]=1;
    path_visited[i]=1;
    for(auto it: adj[i]){
        if(visited[it]==0){
            solve(adj, visited,path_visited,check,it);
        }else if(visited[it] && path_visited[it]){
            check=true;
            return ;
        }
    }
    path_visited[i]=0;
}

    bool canFinish(int n, vector<vector<int>>& grid) {
        vector<int> adj[n];
        for(int i=0; i<grid.size(); i++){
            adj[grid[i][1]].push_back(grid[i][0]);
        }
        vector<int> visited(n,0);
        vector<int> path_visited(n,0);
        for(int i=0; i<n;i++){
            if(visited[i]==0){
                bool check=false;
                solve(adj,visited,path_visited,check,i);
                if(check==true){
                    return false;
                }
            }
        }
        return true;
    }
};