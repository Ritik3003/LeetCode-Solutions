class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        int ans=0;
        while(j>i){
            int left=nums[i];
            int right=nums[j];
            if(left>right){
                int area=abs(j-i)*right;
                j--;
                ans=max(ans,area);
            }else{
                int area=abs(j-i)*left;
                i++;
                ans=max(ans,area);
            }
        }
        return ans;
    }
};