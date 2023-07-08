class Solution {
public:
int solve(vector<int>&nums, vector<vector<int>>&dp, int n, int i, int buy, int fee){
    if(i>=n){
        return 0;
    }
    if(dp[i][buy]!=-1){
        return dp[i][buy];
    }
    int profit=0;
    if(buy==0){
        int buy_karo=solve(nums,dp,n,i+1,1,fee)-nums[i];
        int skip_karo=solve(nums,dp,n,i+1,0,fee);
        profit=max(buy_karo,skip_karo);
    }else{
        int sell_karo=solve(nums,dp,n,i+1,0,fee)+nums[i]-fee;
        int skip_karo=solve(nums,dp,n,i+1,1,fee);
        profit=max(sell_karo,skip_karo);
    }
    return dp[i][buy]=profit;
}


    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,dp,n,0,0,fee);
    }
};