class Solution {
public:
int solve(vector<int>&nums, vector<vector<int>>&dp,int target, int i){
    if(target<0){
        return 0;
    }
    if(i==0){
        return target%nums[i]==0;
    }
    if(target==0 || (target==nums[i] && i==0)){
        return 1;
    }
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    return dp[i][target]=solve(nums,dp,target,i-1) +solve(nums,dp,target-nums[i],i);
}



    int change(int target, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(coins,dp,target,n-1);
    }
};