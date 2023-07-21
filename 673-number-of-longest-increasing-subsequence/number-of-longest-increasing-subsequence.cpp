class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        int length=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j] && 1+dp[j]>dp[i]){
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }else if(nums[i]>nums[j] && dp[i]==1+dp[j]){
                    count[i]=count[i]+count[j];
                }
            }
            length=max(length,dp[i]);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(dp[i]==length){
                ans+=count[i];
            }
        }
        return ans;
    }
};