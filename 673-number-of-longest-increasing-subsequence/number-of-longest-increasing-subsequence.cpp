class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        int ans=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j] && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    count[i]=count[j];
                }else if(nums[i]>nums[j] && dp[i]==1+dp[j]){
                    dp[i]=1+dp[j];
                    count[i]=count[i]+count[j];
                }
            }
            ans=max(ans,dp[i]);
        }
        int ans1=0;
        for(int i=0; i<n; i++){
            if(ans==dp[i]){
                ans1+=count[i];
            }
        }
        return ans1;
    }
};