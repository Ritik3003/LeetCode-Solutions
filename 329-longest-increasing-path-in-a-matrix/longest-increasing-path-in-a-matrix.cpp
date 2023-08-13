class Solution {
public:
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>> &v, int i, int j){
        if (v[i][j] != INT_MIN){
            return v[i][j];
        }
        int output = 1;
        if(i > 0 && matrix[i][j] < matrix[i-1][j]){
            output = max(output, 1+dfs(matrix,v,i-1, j));
        }
        if ( i < matrix.size()-1 && matrix[i][j] < matrix[i+1][j]){
            output = max(output, 1+dfs(matrix,v,i+1, j));
        }
        if ( j > 0 && matrix[i][j] < matrix[i][j-1]){
            output = max(output, 1+dfs(matrix,v,i , j-1));
        }
        if ( j < matrix[i].size()-1 && matrix[i][j] < matrix[i][j+1]){
            output = max(output, 1+dfs(matrix,v, i, j+1));
        }
        v[i][j] = output;
        return output;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=0;
        vector<vector<int>>v;
        for (int i = 0; i < matrix.size(); i++){
            v.push_back(vector<int>(matrix[i].size(), INT_MIN));
        }
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                int a=dfs(matrix,v,i,j);
                ans=max(ans,a);
            }
        }
        return ans;
    }
};