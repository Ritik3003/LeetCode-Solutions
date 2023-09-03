class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n,0);
        vector<int> dp2(n,0);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j] && dp1[i]<1+dp1[j]){
                    dp1[i]=1+dp1[j];
                }
            }
            cout<<dp1[i]<<" ";
        }
        reverse(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j] && dp2[i]<1+dp2[j]){
                    dp2[i]=1+dp2[j];
                }
            }
        }
        reverse(dp2.begin(),dp2.end());
        int ans=0;
        cout<<"\n";
        for(int i=0; i<n; i++){
            if(dp1[i]>0 && dp2[i]>0){
                ans=max(ans,dp1[i]+dp2[i]);
            }
            cout<<dp2[i]<<" ";
        }
        return n-ans-1;
    }
};