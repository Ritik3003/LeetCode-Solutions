class Solution {
public:
bool solve(vector<vector<int>>&graph, vector<int>&visited, vector<int>&path_visited,vector<int>&parent_cycle,int i){
    visited[i]=1;
    path_visited[i]=1;
    for(auto it: graph[i]){
        if(visited[it]==0){
            if(solve(graph,visited,path_visited,parent_cycle,it)){
                return parent_cycle[i]=1;
            }
        }else if(visited[it] && path_visited[it]){
            return parent_cycle[i]=1;
        }
    }
    path_visited[i]=0;
    return false;
}

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,0);
        vector<int> path_visited(n,0);
        vector<int> present_cycle(n,0);
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                solve(graph,visited,path_visited,present_cycle,i);
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(present_cycle[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};