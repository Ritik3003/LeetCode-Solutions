class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        int ans=0;
        set<int> st;
        vector<int> v(26,0);
        for(int i=0; i<n; i++){
            v[s[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            cout<<v[i]<<" ";
            while(st.find(v[i])!=st.end() && v[i]>0){
                ans++;
                v[i]--;
            }
            st.insert(v[i]);
        }
        return ans;
    }
};