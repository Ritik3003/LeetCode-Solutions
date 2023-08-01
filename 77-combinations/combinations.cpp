class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int>&v, int n, int k, int i){
        if(k==0){
            ans.push_back(v);
            return ;
        }
        if(i>n || k<0){
            return ;
        }
        v.push_back(i);
        solve(ans,v,n,k-1,i+1);
        v.pop_back();
        solve(ans,v,n,k,i+1);
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(ans,v,n,k,1);
        return ans;
    }
};