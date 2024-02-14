class Solution {
public:
int solve(vector<int>&dp, int i){
    if(i<=0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int ans=1e9;
    for(int j=1; j*j<=i; j++){
        ans=min(ans,solve(dp,i-j*j)+1);
    }
    return dp[i]=ans;
}

    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=0;
        return solve(dp,n);
    }
};