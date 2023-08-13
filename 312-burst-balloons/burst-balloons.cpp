class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size(), -1));
        return dfs(nums, 0, nums.size()-1, dp);
    }
    int dfs(vector<int>&nums, int i, int j, vector<vector<int>>&dp){
        // cout<<i<<' '<<j<<'\n';
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;
        for(int x = i ;x <= j ; x++){
            int temp = nums[x];
            if(i-1 >=0) temp*= nums[i-1];
            if(j+1 < nums.size()) temp*= nums[j+1];
            maxi = max(maxi, dfs(nums, i, x-1, dp) + temp + dfs(nums, x+1, j, dp));
        }
        return dp[i][j] = maxi;
    }
};