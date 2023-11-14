class Solution {
public:

bool check(vector<int>&nums, int mid, int k){
    int n=nums.size();
    int sum=0;
    for(int i=0; i<n; i++){
        if(nums[i]%mid==0){
            sum+=(nums[i]/mid);
        }else{
            sum+=(nums[i]/mid)+1;
        }
        if(sum>k){
            return false;
        }
    }
    return true;
}

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=1000000000;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(piles,mid,h)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};