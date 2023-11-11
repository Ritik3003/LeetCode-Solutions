class Solution {
public:

int solve(vector<int>&nums, vector<vector<int>>&dp, int start, int end){
    if(start>end){
        return 0;
    }
    if(dp[start][end]!=-1){
        return dp[start][end];
    }
    int ans=INT_MIN;
    for(int k=start; k<=end; k++){
        int step=solve(nums,dp,start,k-1)+solve(nums,dp,k+1,end)+nums[start-1]*nums[k]*nums[end+1];
        ans=max(ans,step);
    }
    return dp[start][end]=ans;
}

    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        reverse(nums.begin(),nums.end());
        nums.push_back(1);
        reverse(nums.begin(),nums.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(nums,dp,1,n);
    }
};