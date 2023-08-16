class Solution {
public:
    vector<int> findArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        int count=nums[0];
        for(int i=1; i<n; i++){
            ans.push_back(nums[i]^count);
            count=nums[i];
        }
        return ans;
    }
};