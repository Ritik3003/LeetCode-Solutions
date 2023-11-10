class Solution {
public:

int solve(string &s, string &t, vector<vector<int>>&dp, int i, int j, int n, int m){
    if(i==n){
        return m-j;
    }
    if(j==m){
        return n-i;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i]==t[j]){
        return dp[i][j]=solve(s,t,dp,i+1,j+1,n,m);
    }
    int insert=solve(s,t,dp,i,j+1,n,m);
    int dele=solve(s,t,dp,i+1,j,n,m);
    int replace=solve(s,t,dp,i+1,j+1,n,m);
    return dp[i][j]=min(insert,min(dele,replace))+1;
}

    int minDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(s,t,dp,0,0,n,m);
    }
};