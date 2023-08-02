class Solution {
public:

void solve(int ind ,vector<int>&nums,vector<vector<int>>&res){
        if(ind == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=ind ; i<nums.size() ; i++){
            swap(nums[ind],nums[i]);
            solve(ind+1,nums,res);
            swap(nums[i],nums[ind]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0,nums,ans);
        return ans;
    }
};