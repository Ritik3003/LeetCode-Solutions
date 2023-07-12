class Solution {
public:
bool solve(vector<vector<int>>&grid, vector<int>&color,int n, int i){
    queue<int> q;
    q.push(i);
    color[i]=0;
    while(q.size()){
        int node=q.front();
        q.pop();
        for(auto it: grid[node]){
            if(color[it]==-1){
                q.push(it);
                color[it]=!color[node];
            }else if(color[it]!=-1 && color[it]==color[node]){
                return false;
            }
        }
    }
    return true;
}

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0; i<n; i++){
            if(color[i]==-1){
                if(!solve(graph,color,n,i)){
                    return false;
                }
            }
        }
        return true;
    }
};