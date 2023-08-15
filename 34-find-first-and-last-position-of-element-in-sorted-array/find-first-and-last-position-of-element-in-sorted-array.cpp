class Solution {
public:

int solve_first(vector<int>&nums, int target){
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=-1;
    while(high>=low){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            ans=mid;
            high=mid-1;
        }else if(nums[mid]>target){
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}
int solve_last(vector<int>&nums, int target){
    int n=nums.size();
    int low=0;
    int high=n-1;
    int ans=-1;
    while(high>=low){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            ans=mid;
            low=mid+1;
        }else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        // if(n==0 && nums[0]==target){
        //     return {0,0};
        // }
        if(n==0){
            return {-1,-1};
        }
        int first=solve_first(nums,target);
        int last=solve_last(nums,target);
        // if(first==-1 && last==-1){
        //     return {};
        // }
        return {first,last};
    }
};