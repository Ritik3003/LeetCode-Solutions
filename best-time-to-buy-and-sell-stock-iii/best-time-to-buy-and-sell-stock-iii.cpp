class Solution {
public:
int solve(vector<int>&nums,vector<vector<vector<int>>>&dp, int n, int i, int buy, int count){
    if(i>=n || count==0){
        return 0;
    }
    if(dp[i][buy][count]!=-1){
        return dp[i][buy][count];
    }
    int profit=0;
    if(buy==0){
        int buy_karo=solve(nums,dp,n,i+1,1,count)-nums[i];
        int skip_karo=solve(nums,dp,n,i+1,0,count);
        profit=max(buy_karo,skip_karo);
    }else{
        int sell_karo=solve(nums,dp,n,i+1,0,count-1)+nums[i];
        int skip_karo=solve(nums,dp,n,i+1,1,count);
        profit=max(sell_karo,skip_karo);
    }
    return dp[i][buy][count]=profit;
}


    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,dp,n,0,0,2);
    }
};