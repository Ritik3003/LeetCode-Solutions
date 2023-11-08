class Solution {
public:
int solve(string &s, vector<vector<int>>&dp, int n, int start, int end){
    if(start>end){
        return 0;
    }
    if(start==end){
        return 1;
    }
    if(dp[start][end]!=-1){
        return dp[start][end];
    }
    int a=0;
    if(s[start]==s[end]){
        a=2+solve(s,dp,n,start+1,end-1);
    }
    int b=solve(s,dp,n,start+1,end);
    int c=solve(s,dp,n,start,end-1);
    return dp[start][end]=max(a,max(b,c));
}



    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return n-solve(s,dp,n,0,n-1);
    }
};