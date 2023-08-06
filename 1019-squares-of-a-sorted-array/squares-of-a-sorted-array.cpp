class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int n=nums.size();
        vector<int> ans(n,0);
        int index=n-1;
        while(i<=j){
            int left=nums[i]*nums[i];
            int right=nums[j]*nums[j];
            if(left>right){
                ans[index--]=left;
                i++;
            }else{
                ans[index--]=right;
                j--;
            }
        }
        return ans;
    }
};