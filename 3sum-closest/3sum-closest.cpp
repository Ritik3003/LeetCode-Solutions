class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mini=INT_MAX;
        int ans=0;
        for(int i=0; i<n-2; i++){
            int start=i+1;
            int end=n-1;
            while(start<end){
                int sum=nums[i]+nums[start]+nums[end];
                if(sum==target){
                    return target;
                }else if(sum<target){
                    start++;
                }else{
                    end--;
                }
                // ans=min(ans,abs(target-sum));
                if(mini>abs(target-sum)){
                    mini=abs(target-sum);
                    ans=sum;
                }
            }
        }
        return ans;
    }
};