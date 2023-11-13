class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int index=0;
        for(int i=0; i<n; i++){
            if(matrix[i][0]==target){
                return true;
            }else if(matrix[i][0]<target){
                index=i;
            }
        }
        for(int i=0; i<m; i++){
            if(matrix[index][i]==target){
                return true;
            }
        }
        return false;
    }
};