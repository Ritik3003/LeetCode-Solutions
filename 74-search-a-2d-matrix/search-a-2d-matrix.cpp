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
        // for(int i=0; i<n; i++){
        //     if(matrix[i][0]==target){
        //         return true;
        //     }else if(matrix[i][0]<target){
        //         index=i;
        //     }
        // }
        cout<<index;
        for(int i=0; i<m; i++){
            if(matrix[index][i]==target){
                return true;
            }
        }
        return false;
    }
};