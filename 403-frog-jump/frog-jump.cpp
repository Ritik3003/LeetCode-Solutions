class Solution {
public:
bool solve(vector<int>&nums, vector<vector<int>>&dp, int n, int i, int jump){
    if(i>=n){
        return false;
    }
    if(i==n-1){
        return true;
    }
    if(dp[i][jump]!=-1){
        return dp[i][jump];
    }
    bool ans=false;
    for(int index=i+1; index<n; index++){
        if(nums[index]-nums[i]>jump+1){
            break;
        }
        for(int t=-1; t<2; t++){
            if(nums[index]-nums[i]==jump+t){
                ans=ans || solve(nums,dp,n,index,jump+t);
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
        return solve(stones, dp,n,1,1);
    }
};