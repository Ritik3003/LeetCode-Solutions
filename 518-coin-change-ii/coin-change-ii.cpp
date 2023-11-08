class Solution {
public:
int solve(vector<int>&nums, vector<vector<int>>&dp, int target, int i){
    if(i<0 || target<0){
        return 0;
    }
    if(target==0 || (target==nums[i] && i==0)){
        return 1;
    }
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    int not_take=solve(nums,dp,target,i-1);
    int take=0;
    if(target>=nums[i]){
        take=solve(nums,dp,target-nums[i],i);
    }
    return dp[i][target]=take+not_take;
}

    int change(int target, vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(nums,dp,target,n-1);
    }
};