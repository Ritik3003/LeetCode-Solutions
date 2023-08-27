class Solution {
public:
bool solve(vector<int>&nums, vector<vector<int>>&dp, int n, int i, int jump){
    if(i==n-1){
        return true;
    }
    if(i>=n){
        return false;
    }
    if(dp[i][jump]!=-1){
        return dp[i][jump];
    }
    bool ans=false;
    for(int j=i+1; j<n; j++){
        if(nums[j]-nums[i]>jump+1){
            break;
        }
        for(int k=-1; k<2; k++){
            if(nums[j]-nums[i]==jump+k){
                ans=ans || solve(nums,dp,n,j,jump+k);
            }
        }
    }
    return dp[i][jump]=ans;
}


    bool canCross(vector<int>& stones) {
        int n=stones.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        if(stones[1]-stones[0]>1){
            return false;
        }
        return solve(stones,dp,n,1,1);
    }
};