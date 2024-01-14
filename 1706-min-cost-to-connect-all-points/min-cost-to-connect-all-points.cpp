class Solution {
public:

int findparent(int node, vector<int>&parent){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=findparent(parent[node],parent);
}

void union_set(int u, int v, vector<int>&rank, vector<int> &parent){
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

    int minCostConnectPoints(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<pair<int,pair<int,int>>>v;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int x=abs(grid[i][0]-grid[j][0])+abs(grid[i][1]-grid[j][1]);
                v.push_back({x,{i,j}});
            }
        }
        sort(v.begin(),v.end());
        int m=v.size();
        vector<int> rank(m+1,0);
        int ans=0;
        vector<int> parent(m+1,0);
        for(int i=0; i<=m; i++){
            parent[i]=i;
        }
        for(int i=0; i<m; i++){
            int cost=v[i].first;
            int a=v[i].second.first;
            int b=v[i].second.second;
            a=findparent(a,parent);
            b=findparent(b,parent);
            if(a!=b){
                union_set(a,b,rank,parent);
                ans+=cost;
            }
        }
        return ans;
    }
};