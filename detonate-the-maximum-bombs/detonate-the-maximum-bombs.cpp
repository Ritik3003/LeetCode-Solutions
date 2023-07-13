class Solution {
public:
void solve(vector<int>adj[], vector<int>&visited, int &count,int i){
    visited[i]=1;
    count++;
    for(auto it: adj[i]){
        if(visited[it]==0){
            solve(adj,visited,count,it);
        }
    }
}


    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            long long int i_x=bombs[i][0];
            long long int i_y=bombs[i][1];
            long long int i_r=bombs[i][2];
            for(int j=0; j<n; j++){
                if(i==j){
                    continue;
                }
                long long int j_x=abs(bombs[j][0]-i_x); 
                long long int j_y=abs(bombs[j][1]-i_y);
                long long int j_r=bombs[j][2];
                if(j_x*j_x+j_y*j_y<=i_r*i_r){
                    adj[i].push_back(j);
                }
            }
        }
        // for(int i=0; i<n; i++){
        //     cout<<i<<": ";
        //     for(auto it: adj[i]){
        //         cout<<it<<" ";
        //     }
        //     cout<<"\n";
        // }
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            int count=0;
            vector<int> visited(n,0);
            solve(adj,visited,count,i);
            ans=max(ans,count);
        }
        return ans;
    }
};