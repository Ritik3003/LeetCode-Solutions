class Solution {
public:

bool check(vector<int>&nums,int mid,  int k){
    int count=0;
    for(int i=0; i<nums.size(); i++){
        int temp=nums[i]/mid;
        if(nums[i]%mid!=0){
            temp++;
        }
        count+=temp;
        if(count>k){
            return false;
        }
    }
    return true;
}

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(nums,mid,threshold)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};