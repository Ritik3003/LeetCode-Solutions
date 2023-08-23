class Solution {
public:
void solve(vector<int>&nums, vector<int>&ans, int sum, int i){
    if(i==nums.size()){
        ans.push_back(sum);
        return ;
    }
    solve(nums,ans,sum,i+1);
    solve(nums,ans,sum+nums[i],i+1);
}


    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int> nums1,nums2;
        for(int i=0; i<n/2; i++){
            nums1.push_back(nums[i]);
        }
        for(int i=n/2; i<n; i++){
            nums2.push_back(nums[i]);
        }
        vector<int> set1,set2;
        solve(nums1,set1,0,0);
        solve(nums2,set2,0,0);
        sort(set1.begin(),set1.end());
        sort(set2.begin(),set2.end());
        int ans=INT_MAX;
        for(int i=0; i<set1.size(); i++){
            int left=0;
            int right=set2.size()-1;
            while(left<=right){
                int mid=left+(right-left)/2;
                int sum=set2[mid]+set1[i];
                if(sum==goal){
                    return 0;
                }
                ans=min(ans,abs(sum-goal));
                if(sum>goal){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }
        }
        return ans;
    }
};