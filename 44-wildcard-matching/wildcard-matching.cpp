class Solution {
public:
bool solve(string &s, string &t, vector<vector<int>>&dp, int i, int j){
    if(j<0 && i>=0){
        return false;
    }
    if(i<0 && j<0){
        return true;
    }
    if(i<0 && j>=0){
        for(int k=0; k<=j; k++){
            if(t[k]!='*'){
                return false;
            }
        }
        return true;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(s[i]==t[j] || t[j]=='?'){
        return dp[i][j]=solve(s,t,dp,i-1,j-1);
    }
    if(t[j]=='*'){
        return dp[i][j]=solve(s,t,dp,i-1,j) || solve(s,t,dp,i,j-1);
    }
    return dp[i][j]= false;

}

    bool isMatch(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(s,t,dp,n-1,m-1);
    }
};