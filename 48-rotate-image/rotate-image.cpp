class Solution {
public:
    void rotate(vector<vector<int>>& nums) {
        int n=nums.size();
        int m=nums[0].size();
        for(int i=0; i<n; i++){
            for(int j=i; j<m; j++){
                swap(nums[i][j],nums[j][i]);
            }
        }
        int i=0;
        while(i<n){
            int left=0;
            int right=m-1;
            while(left<=right){
                swap(nums[i][left],nums[i][right]);
                left++;
                right--;
            }
            i++;
        }
    }
};