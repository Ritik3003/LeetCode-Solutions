class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        vector<int> v(26,0);
        for(int i=0; i<chars.size(); i++){
            v[chars[i]-'a']++;
        }
        int n=words.size();
        for(int i=0; i<n; i++){
            int m=words[i].size();
            vector<int> temp=v;
            bool check=true;
            for(int j=0;j<m; j++){
                if(temp[words[i][j]-'a']==0){
                    check=false;
                    break;
                }
                temp[words[i][j]-'a']--;
            }
            if(check){
                // cout<<i<<" ";
                ans+=m;
            }
        }
        return ans;
    }
};