class Solution {
public:

int solve(vector<int>&nums, vector<int>&dp, int i, int n){
    if(i>=n){
        return 1e9;
    }
    if(i==n-1){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int ans=1e9;
    for(int j=1; j<=nums[i]; j++){
        ans=min(ans,solve(nums,dp,j+i,n)+1);
    }
    return dp[i]=ans;
}

    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums,dp,0,n);
    }
};