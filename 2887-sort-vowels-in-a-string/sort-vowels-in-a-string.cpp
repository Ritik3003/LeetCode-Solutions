class Solution {
public:
    string sortVowels(string s) {
        string x="";
        int n=s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U'){
                x+=s[i];
            }
        }
        sort(x.begin(),x.end());
        int count=0;
        for(int i=0; i<n; i++){
            if(s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U'){
                s[i]=x[count];
                count++;
            }
        }
        return s;
    }
};