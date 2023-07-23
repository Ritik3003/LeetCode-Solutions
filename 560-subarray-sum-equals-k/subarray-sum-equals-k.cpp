class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        unordered_map<int,int> m;
        m[sum]++;
        int ans=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            int x=sum-k;
            ans+=m[x];
            m[sum]++;
        }
        return ans;
    }
};