class Solution {
public:
int solve(vector<int>&nums, vector<vector<vector<int>>>&dp, int i,int buy, int k, int n){
    if(i>=n || k<=0){
        return 0;
    }
    if(dp[i][buy][k]!=-1){
        return dp[i][buy][k];
    }
    int profit=0;
    if(buy==0){
        int buy_karo=solve(nums,dp,i+1,1,k,n)-nums[i];
        int skip=solve(nums,dp,i+1,0,k,n);
        profit=max(buy_karo,skip);
    }else{
        int sell_karo=solve(nums,dp,i+1,0,k-1,n)+nums[i];
        int skip=solve(nums,dp,i+1,1,k,n);
        profit=max(sell_karo,skip);
    }
    return dp[i][buy][k]=profit;
}

    int maxProfit(int k, vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(nums,dp,0,0,k,n);
    }
};