class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0; i<n; i++){
            if(nums[i]==1){
                int x=i+1;
                int count=1;
                while(x<n && nums[x]==1){
                    count++;
                    x++;
                }
                // cout<<count<<"\n";
                ans=max(ans,count);
            }
        }
        return ans;
    }
};