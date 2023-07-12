class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        int ans=0;
        int start=0;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(m[s[i]]){
                while(s[start]!=s[i]){
                    m[s[start]]=0;
                    start++;
                }
                start++;
            }else{
                m[s[i]]++;
                ans=max(ans,i-start+1);
            }
        }
        return ans;
    }
};