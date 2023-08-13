class Solution {
public:
int solve(string &s, vector<vector<int>>&dp, int n, int i, int pre, int k){
    if(i>=n){
        return 0;
    }
    if(pre!=-1 && dp[i][pre]!=-1){
        return dp[i][pre];
    }
    int not_take=solve(s,dp,n,i+1,pre,k);
    int take=0;
    if(pre==-1 || abs(s[i]-'a'-pre)<=k){
        take=1+solve(s,dp,n,i+1,s[i]-'a',k);
    }
    if(pre!=-1){
        return dp[i][pre]=max(take,not_take);
    }
    return max(take,not_take);
}


    int longestIdealString(string s, int k) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(30,-1));
        return solve(s,dp,n,0,-1,k);
    }
};