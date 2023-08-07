class Solution {
public:
void solve(vector<string>&ans, int open, int close, int n, string s){
    if(s.size()==2*n){
        ans.push_back(s);
        return ;
    }
    if(open<n){
        solve(ans,open+1,close,n,s+'(');
    }
    if(close<open){
        solve(ans,open,close+1,n,s+')');
    }
}

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans,0,0,n,"");
        return ans;
    }
};