class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& grid) {
        vector<int> adj[n];
        for(int i=0; i<grid.size(); i++){
            adj[grid[i][1]].push_back(grid[i][0]);
        }
        vector<int> indegree(n,0);
        for(int i=0; i<n; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        int count=0;
        while(q.size()){
            int node=q.front();
            q.pop();
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            ans.push_back(node);
            count++;
        }
        if(count!=n){
            return {};
        }
        return ans;
    }
};