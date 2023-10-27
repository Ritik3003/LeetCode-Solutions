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

int solve(string &s, vector<vector<int>>&dp, int start, int end, int &maxi, int &index){
    if(start>end){
        return 0;
    }
    if(start==end){
        return 1;
    }
    if(dp[start][end]!=-1){
        return dp[start][end];
    }
    int a=0;
    if(s[start]==s[end]){
        if(check(s,start,end)){
            int length=end-start+1;
            if(length>maxi){
                index=start;
                maxi=length;
            }
            return dp[start][end]=length;
        }
    }
    int b=solve(s,dp,start+1,end,maxi, index);
    int c=solve(s,dp,start,end-1,maxi,index);
    return dp[start][end]=max(b,c);
}

    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int maxi=1;
        // int ans=1;
        string ans="";
        int index=0;
        solve(s,dp,0,n-1,maxi,index);
        while(maxi--){
            ans+=s[index++];
        }
        return ans;
    }
};