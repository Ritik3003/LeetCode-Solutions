class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            vector<int> x = it;
            adj[x[0]].push_back({x[1], x[2]});
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {src, 0}});
        vector<int>dist(n,1e9);
        dist[src]=0;
        while(pq.size()){
            auto it=pq.top();
            pq.pop();
            int stop=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stop>k){
                continue;
            }
            for(auto x: adj[node]){
                int edge_weight=x.second;
                int adjacent_node=x.first;
                if( stop<=k && dist[adjacent_node]>cost+edge_weight){
                    dist[adjacent_node]=cost+edge_weight;
                    pq.push({stop+1,{adjacent_node,cost+edge_weight}});
                }
            }
        }
        for(int i=0; i<n; i++){
            cout<<dist[i]<<" ";
        }
        if(dist[dst]>=1e9){
            return -1;
        }
        return dist[dst];
    }
};