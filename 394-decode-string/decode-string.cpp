class Solution {
public:
string solve(string &s, int &i){
    string ans="";
    while(i<s.size() && s[i]!=']'){
        if(i<s.size() && isdigit(s[i])){
            int k=0;
            while(i<s.size() && isdigit(s[i])){
                k=k*10+(s[i]-'0');
                i++;
            }
            i++;
            string result=solve(s,i);
            while(k--){
                ans+=result;
            }
            i++;
        }else{
            ans+=s[i];
            i++;
        }
    }
    return ans;
}

    string decodeString(string s) {
        int i=0;
        return solve(s,i);   
    }
};