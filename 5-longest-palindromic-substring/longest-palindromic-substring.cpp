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
int solve(string &s, vector<vector<int>>&dp, int &index,int &maxi,int start,int end){
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
        return dp[start][end]=solve(s,dp,index,maxi,start+1,end-1)+2;
    }
    int c=0;
    // if(s[start]==s[end]){
    //     c=2+solve(s,dp,index,maxi,start,e)
    // }
    int a=solve(s,dp,index,maxi,start+1,end);
    int b=solve(s,dp,index,maxi,start,end-1);
    return dp[start][end]=max(a,b);

}

    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int index=0;
        int maxi=1;
        int length=solve(s,dp,index,maxi,0,n-1);
        string ans="";
        while(length--){
            ans+=s[index++];
        }
        return ans;
    }
};