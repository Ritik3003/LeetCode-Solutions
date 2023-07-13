class Solution {
public:
int solve(vector<int>&nums,vector<int>&dp, int n, int i){
    if(i>=n){
        return 1e5;
    }
    if(i==n-1){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int ans=1e5;
    for(int j=1; j<=nums[i]; j++){
        ans=min(ans,1+solve(nums,dp,n,i+j));
    }
    return dp[i]=ans;
}


    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return solve(nums,dp,n,0);
    }
};