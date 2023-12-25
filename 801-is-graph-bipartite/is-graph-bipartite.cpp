class Solution {
public:

void solve(vector<vector<int>>&grid, vector<int>&visited, vector<int>&color, int i, bool & check){
    queue<int> q;
    q.push(i);
    color[i]=0;
    visited[i]=1;
    while(q.size()){
        int node=q.front();
        q.pop();
        for(auto it: grid[node]){
            if(visited[it]==0){
                q.push(it);
                visited[it]=1;
                color[it]=!color[node];
            }else if(visited[it]==1 && color[node]==color[it]){
                check=false;
                return ;
            }
        }
    }
}

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,0);
        bool check=true;
        vector<int> color(n,-1);
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                solve(graph,visited,color,i,check);
                if(check==false){
                    return false;
                }
            }
        }
        return check;
    }
};