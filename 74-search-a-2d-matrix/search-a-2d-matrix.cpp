class Solution {
public:
int solve(vector<vector<int>>&matrix, int target){
    int n=matrix.size();
    int m=matrix[0].size();
    int low=0;
    int ans=0;
    int high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(matrix[mid][0]==target){
            return mid;
        }else if(matrix[mid][0]>target){
            high=mid-1;
        }else{
            ans=mid;
            low=mid+1;
        }
    }
    return ans;
}

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int index=solve(matrix,target);
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[index][mid]==target){
                return true;
            }else if(matrix[index][mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return false;
    }
};