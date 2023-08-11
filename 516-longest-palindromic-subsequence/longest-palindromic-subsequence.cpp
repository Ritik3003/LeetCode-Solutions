class Solution {
public:
int solve(string &s, vector<vector<int>>&dp, int start, int end){
    if(start>end){
        return 0;
    }
    if(start==end){
        return 1;
    }
    if(dp[start][end]!=-1){
        return dp[start][end];
    }
    if(s[start]==s[end]){
        return dp[start][end]=2+solve(s,dp,start+1,end-1);
    }
    int a=solve(s,dp,start+1,end);
    int b=solve(s,dp,start,end-1);
    return dp[start][end]=max(a,b);
}

    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(s,dp,0,n-1);
    }
};