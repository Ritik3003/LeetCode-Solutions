class Solution {
public:
bool check(string &s, int start, int end){
    while(start<=end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int solve(string &s, vector<vector<int>>&dp, int &maxi, int &index, int start, int end){
    if(start>end){
        return 0;
    }
    if(start==end){
        return 1;
    }
    if(dp[start][end]!=-1){
        return dp[start][end];
    }
    if(check(s,start,end)){
        int length=end-start+1;
        if(length>maxi){
            maxi=length;
            index=start;
        }
        return dp[start][end]=length;
    }
    return dp[start][end]=max(solve(s,dp,maxi,index,start+1,end),solve(s,dp,maxi,index,start,end-1));

}

    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        int ans=1;
        int index=0;
        solve(s,dp,ans,index,0,n-1);
        string x="";
        while(ans--){
            x+=s[index++];
        }
        return x;
    }
};