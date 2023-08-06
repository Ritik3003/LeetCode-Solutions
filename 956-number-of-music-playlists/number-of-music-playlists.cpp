class Solution {
public:

    long long int helper(int n,vector<vector<int>>&dp, int k, int goal){
        if(n==0 and goal==0) 
            return 1;
        if(n==0 || goal==0) 
            return 0;
        if(dp[n][goal]!=-1){
            return dp[n][goal];
        }
        int mod = 1e9 + 7;
        long long int a = (helper(n-1,dp, k, goal-1)*n);
        long long int b = (helper(n,dp, k, goal-1)*(max(n-k, 0)));
        return dp[n][goal]=(a+b)%mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>>dp(n+1,vector<int>(goal+1,-1));
        return helper(n,dp,k,goal);
    }
};