class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int ans=0;
        int count=0;
        while(j<n){
            if(nums[j]==1){
                j++;
                ans=max(ans,j-i);
                continue;
            }
            if(nums[j]==0 && k){
                k--;
                j++;
                ans=max(ans,j-i);
                continue;
            }else if(nums[j]==0 && k==0){
                while(k==0){
                    if(nums[i]==0){
                        k++;
                    }
                    i++;
                }
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};