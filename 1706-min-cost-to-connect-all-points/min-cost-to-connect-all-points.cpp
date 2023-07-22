class Solution {
public:
int findparent(int node, vector<int>&parent){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=findparent(parent[node],parent);
}
void union_set(int u, int v, vector<int>&parent, vector<int>&rank){
    u=findparent(u,parent);
    v=findparent(v,parent);
    if(rank[u]>rank[v]){
        rank[u]++;
        parent[v]=u;
    }else{
        rank[v]++;
        parent[u]=v;
    }
}

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,pair<int,int>>> adj;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int distance=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj.push_back({distance,{i,j}});
            }
        }
        sort(adj.begin(),adj.end());
        int ans=0;
        int m=adj.size();
        vector<int> parent(m+1,0);
        vector<int> rank(m+1,0);
        for(int i=0; i<=m; i++){
            parent[i]=i;
        }
        for(int i=0; i<m; i++){
            int u=findparent(adj[i].second.first,parent);
            int v=findparent(adj[i].second.second,parent);
            if(u!=v){
                ans+=adj[i].first;
                union_set(u,v,parent,rank);
            }
        }
        return ans;
    }
};