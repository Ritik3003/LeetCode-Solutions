class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        for(int i=0; i<n; i++){
            unsigned int x=nums[i];
            for(int j=i; j<n && k%nums[j]==0; j++){
                x=lcm(x,nums[j]);
                if(x==k){
                    ans++;
                }
            }
        }
        return ans;
    }
};