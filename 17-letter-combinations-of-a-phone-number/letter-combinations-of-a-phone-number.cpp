class Solution {
public:
vector<string> solve(string &digits, map<int,string>&m, int i){
    if(i==digits.size()){
        return {""};
    }
    vector<string> ans;
    vector<string > temp=solve(digits,m,i+1);
    for(auto it: m[digits[i]-'0']){
        for(auto i: temp){
            ans.push_back(it+i);
        }
    }
    return ans;
}

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        map<int,string> m;
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        return solve(digits,m,0);
    }
};