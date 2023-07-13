class Solution {
public:
bool solve(vector<int>adj[], vector<int>&visited,vector<int>&path_visited,int i){
    visited[i]=1;
    path_visited[i]=1;
    for(auto it: adj[i]){
        if(visited[it]==0){
            if(solve(adj,visited,path_visited,it)){
                return true;
            }
        }else if(visited[it] && path_visited[it]){
            return true;
        }
    }
    path_visited[i]=0;
    return false;
}

    bool canFinish(int n, vector<vector<int>>& graph) {
        vector<int> adj[n];
        for(int i=0; i<graph.size(); i++){
            adj[graph[i][1]].push_back(graph[i][0]);
        }
        vector<int> visited(n,0);
        vector<int> path_visited(n,0);
        for(int i=0;i<n; i++){
            if(visited[i]==0){
                if(solve(adj,visited,path_visited,i)){
                    return false;
                }
            }
        }
        return true;
    }
};