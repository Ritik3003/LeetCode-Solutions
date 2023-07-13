class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& word) {
        unordered_set<string> st;
        for(int i=0; i<word.size(); i++){
            st.insert(word[i]);
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(q.size()){
            string s=q.front().first;
            int step=q.front().second;
            q.pop();
            if(s==endWord){
                return step;
            }
            for(int i=0; i<s.size(); i++){
                char original=s[i];
                for(char j='a'; j<='z'; j++){
                    s[i]=j;
                    if(st.find(s)!=st.end()){
                        st.erase(s);
                        q.push({s,step+1});
                    }
                }
                s[i]=original;
            }
        }
        return 0;
    }
};