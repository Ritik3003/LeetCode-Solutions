class Solution {
public:
bool solve(vector<int>&nums, vector<int>&dp, int i, int n){
    if(i>=n || i<0 || nums[i]<0){
        return false;
    }
    if(nums[i]==0){
        return true;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    nums[i]=-nums[i];
    return dp[i]=solve(nums,dp,i+nums[i],n) || solve(nums,dp,i-nums[i],n);
}

    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return solve(arr,dp,start,n);
    }
};