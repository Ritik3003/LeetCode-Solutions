class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // vector<int> v(257,0);
        map<int,int> v;
        int n=s.size();
        // string x="";
        // for(int i=0; i<n; i++){
        //     if(s[i]!=' '){
        //         x+=s[i];
        //     }
        // }
        // s=x;
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            v[s[j]-'a']++;
            if(v[s[j]-'a']==2){
                while(v[s[j]-'a']==2){
                    v[s[i]-'a']--;
                    i++;
                }
            }else{
                ans=max(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
};