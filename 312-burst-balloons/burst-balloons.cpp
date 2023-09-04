class Solution {
public:
int solve(vector<int>&nums, vector<vector<int>>&dp, int i, int j){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans=INT_MIN;
    for(int k=i; k<=j; k++){
        int step=solve(nums,dp,i,k-1)+solve(nums,dp,k+1,j)+nums[i-1]*nums[k]*nums[j+1];
        ans=max(ans,step);
    }
    return dp[i][j]=ans;
}


    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        reverse(nums.begin(),nums.end());
        nums.push_back(1);
        reverse(nums.begin(),nums.end());
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return solve(nums,dp,1,n);
    }
};