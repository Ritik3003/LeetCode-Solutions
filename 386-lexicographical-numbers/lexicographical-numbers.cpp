class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>x,ans;
        vector<string> s;
        for(int i=1; i<=n; i++){
            s.push_back(to_string(i));
        }
        sort(s.begin(),s.end());
        for(int i=0; i<s.size(); i++){
            ans.push_back(stoi(s[i]));
        }
        return ans;
    }
};