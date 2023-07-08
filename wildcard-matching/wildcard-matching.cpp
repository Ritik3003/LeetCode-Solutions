class Solution {
public:
bool solve(string &s, string &p, vector<vector<int>>&dp, int i, int j){
    if(i<0 && j<0){
        return true;
    }
    if(i<0 && j>=0){
        for(int k=0; k<=j; k++){
            if(p[k]!='*'){
                return false;
            }
        }
        return true;
    }
    if(i>=0 && j<0){
        return false;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i]==p[j] || p[j]=='?'){
        return dp[i][j]=solve(s,p,dp,i-1,j-1);
    }
    if(p[j]=='*'){
        return dp[i][j]=solve(s,p,dp,i-1,j) || solve(s,p,dp,i,j-1);
    }
    return false;
}


    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(s,p,dp,n-1,m-1);
    }
};