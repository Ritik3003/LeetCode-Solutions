class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>v(n,0);
        vector<vector<int>> a(n,vector<int> (n,0));
        for(int i=0; i<roads.size(); i++){
            v[roads[i][0]]++;
            v[roads[i][1]]++;
            a[roads[i][0]][roads[i][1]]=1;
            a[roads[i][1]][roads[i][0]]=1;
        }
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j && a[i][j]==1 && a[j][i]==1){
                    ans=max(ans,v[i]+v[j]-1);
                }else if(i!=j){
                    ans=max(ans,v[i]+v[j]);
                }
            }
        }
        return ans;
    }
};