class Solution {
public:
int solve(string &s, vector<vector<int>>&dp, int i, int pre, int n, int k){
    if(i>=n){
        return 0;
    }
    if(pre!=-1 && dp[i][pre]!=-1){
        return dp[i][pre];
    }
    int take=0;
    if(pre==-1 || abs(s[i]-'a'-pre)<=k){
        take=solve(s,dp,i+1,s[i]-'a',n,k)+1;
    }
    int not_take=solve(s,dp,i+1,pre,n,k);
    if(pre!=-1){
        return dp[i][pre]=max(take,not_take);
    }
    return max(take,not_take);
}


    int longestIdealString(string s, int k) {
        int n=s.size();
        vector<vector<int>> dp(100001,vector<int>(51,-1));
        return solve(s,dp,0,-1,n,k);
    }
};