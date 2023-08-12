class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1; i<n; i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        int sum=0;
        for(int i=0; i<n; i++){
            int right=prefix[n-1]-prefix[i];
            if(sum==right){
                return i;
            }
            sum+=nums[i];
        }
        return -1;
    }
};