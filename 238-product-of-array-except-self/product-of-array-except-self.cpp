class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> from_begin(n,0);
        vector<int> from_end(n,0);
        from_begin[0]=1;
        from_end[0]=1;
        for(int i=1; i<n; i++){
            from_begin[i]=from_begin[i-1]*nums[i-1];
            from_end[i]=from_end[i-1]*nums[n-i];
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            ans.push_back(from_begin[i]*from_end[n-i-1]);
        }
        return ans;
    }
};