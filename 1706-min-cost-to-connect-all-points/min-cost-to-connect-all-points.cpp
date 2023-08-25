class Solution {
public:
int find_parent(int node, vector<int>&parent){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=find_parent(parent[node],parent);
}

void union_set(int u, int v, vector<int>&parent, vector<int>&rank){
    u=find_parent(u,parent);
    v=find_parent(v,parent);
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
        vector<pair<int,pair<int,int>>>v;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int distance=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                v.push_back({distance,{i,j}});
            }
        }
        sort(v.begin(),v.end());
        int m=v.size();
        vector<int> parent(m+1,0);
        vector<int> rank(m+1,0);
        for(int i=0; i<=m; i++){
            parent[i]=i;
        }
        int ans=0;
        for(int i=0; i<m; i++){
            auto it=v[i];
            int distance=it.first;
            int x=it.second.first;
            int y=it.second.second;
            int u=find_parent(x,parent);
            int v=find_parent(y,parent);
            if(u!=v){
                ans+=distance;
                union_set(x,y,parent,rank);
            }
        }
        return ans;
    }
};