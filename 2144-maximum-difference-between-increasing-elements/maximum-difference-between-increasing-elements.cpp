class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=INT_MIN;
        int n=nums.size();
        int pre=nums[0];
        for(int i=1; i<n; i++){
            if(pre<nums[i]){
                ans=max(ans,nums[i]-pre);
            }else{
                pre=nums[i];
            }
        }
        if(ans==INT_MIN){
            return -1;
        }
        return ans;
    }
};