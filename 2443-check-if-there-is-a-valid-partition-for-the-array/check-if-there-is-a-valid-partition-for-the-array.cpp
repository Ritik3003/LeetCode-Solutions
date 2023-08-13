class Solution {
public:
bool solve(vector<int>&nums, vector<int>&dp, int i, int n){
    if(i>=n){
        return true;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    if(i+1<n && nums[i]==nums[i+1]){
        dp[i]=solve(nums,dp,i+2,n);
        if(dp[i]){
            return true;
        }
    }
    if(i+2<n && nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
        dp[i]=solve(nums,dp,i+3,n);
        if(dp[i]){
            return true;
        }
    }
    if(i+2<n && nums[i+1]-nums[i]==1 && nums[i+2]-nums[i+1]==1){
        dp[i]=solve(nums,dp,i+3,n);
        if(dp[i]){
            return true;
        }
    }
    return dp[i]=false;
}

    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums,dp,0,n);
    }
};