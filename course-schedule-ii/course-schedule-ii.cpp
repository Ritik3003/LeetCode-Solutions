class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>&v) {
        int x=v.size();
        vector<int> adj[n];
        for(int i=0; i<x; i++){
            adj[v[i][1]].push_back(v[i][0]);
        }
        vector<int> indegree(n,0);
        queue<int> q;
        for(int i=0; i<n; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        vector<int> ans;
        while(q.size()){
            int node=q.front();
            q.pop();
            count++;
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            ans.push_back(node);
        }
        if(count!=n){
            vector<int> v;
            return v;
        }
        return ans;
    }
};