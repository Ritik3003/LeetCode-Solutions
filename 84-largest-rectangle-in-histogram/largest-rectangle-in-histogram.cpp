class Solution {
public:
vector<int> solve_next(vector<int>&nums, int n){
    stack<int> s;
    vector<int> ans;
    s.push(-1);
    for(int i=n-1; i>=0; i--){
        while(s.top()!=-1 && nums[s.top()]>=nums[i]){
            s.pop();
        }
        ans.push_back(s.top());
        s.push(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

vector<int> solve_pre(vector<int>&nums, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans;
    for(int i=0; i<n; i++){
        while(s.top()!=-1 && nums[s.top()]>=nums[i]){
            s.pop();
        }
        ans.push_back(s.top());
        s.push(i);
    }
    return ans;
}


    int largestRectangleArea(vector<int>& nums) {
        int n=nums.size();
        vector<int> next=solve_next(nums,n);
        vector<int> pre=solve_pre(nums,n);
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            if(next[i]==-1){
                next[i]=n;
            }
            int area=(next[i]-pre[i]-1)*nums[i];
            ans=max(ans,area);
        }
        return ans;
    }
};