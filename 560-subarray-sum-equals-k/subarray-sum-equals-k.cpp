class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        int sum=0;
        m[sum]++;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            int x=sum-k;
            ans+=m[x];
            m[sum]++;
        }
        return ans;
    }
};