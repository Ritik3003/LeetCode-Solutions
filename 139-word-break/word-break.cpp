class Solution {
public:
bool solve(string &st, set<string> &s,vector<int>&dp, int i){
    if(i==st.size()){
        return true;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    string temp="";
    for(int j=i; j<st.size(); j++){
        temp+=st[j];
        if(s.find(temp)!=s.end()){
            if(solve(st,s,dp,j+1)){
                return dp[i]=true;
            }
        }
    }
    return dp[i]=false;
}


    bool wordBreak(string st, vector<string>& word) {
        int n=word.size();
        set<string> s;
        for(int i=0; i<n; i++){
            s.insert(word[i]);
        }
        vector<int> dp(301,-1);
        return solve(st,s,dp,0);
    }
};