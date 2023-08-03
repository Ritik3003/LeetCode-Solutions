class Solution {
public:

bool check(int i, int j, int n){
    if(i<0 || j<0 || i>=n || j>=n){
        return false;
    }
    return true;
}

bool reach(vector<vector<int>>&grid, vector<vector<int>>&visited, int mid, int i, int j, int n){
    if(i==n-1 && j==n-1){
        return true;
    }
    visited[i][j]=1;
    int d[5]={1,0,-1,0,1};
    for(int k=0; k<4; k++){
        int new_x=i+d[k];
        int new_y=j+d[k+1];
        if(check(new_x,new_y,n) && visited[new_x][new_y]==0 && grid[new_x][new_y]<=mid && grid[i][j]<=mid){
            if(reach(grid,visited,mid,new_x,new_y,n)){
                return true;
            }
        }
    }
    return false;
}


    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int high=n*n-1;
        int low=0;
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            vector<vector<int>> visited(n,vector<int>(n,0));
            if(reach(grid,visited,mid,0,0,n)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};