class Solution {
public:

void solve(vector<int>&nums, vector<vector<int>>&ans, vector<int>&v, int target, int i){
    if(i>=nums.size() || target<0){
        return ;
    }
    if(target==0){
        ans.push_back(v);
        return ;
    }
    solve(nums,ans,v,target,i+1);
    v.push_back(nums[i]);
    solve(nums,ans,v,target-nums[i],i);
    v.pop_back();
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(candidates,ans,v,target,0);
        return ans;
    }
};