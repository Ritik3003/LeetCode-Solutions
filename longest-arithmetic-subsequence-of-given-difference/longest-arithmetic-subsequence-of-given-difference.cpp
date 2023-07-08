class Solution {
public:
    int longestSubsequence(vector<int>& nums, int d) {
        map<int,int> m;
        int n=nums.size();
        vector<int> dp(n);
        int ans=0;
        for(int i=0; i<n; i++){
            int num=nums[i]-d;
            int a=0;
            if(m.find(num)!=m.end()) a=dp[m[num]];
            dp[i]=1+a;
            m[nums[i]]=i;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};