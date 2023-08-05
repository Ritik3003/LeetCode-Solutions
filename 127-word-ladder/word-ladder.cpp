class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& word) {
        set<string> s;
        for(int i=0; i<word.size(); i++){
            s.insert(word[i]);
        }
        set<pair<int, string>> q;
        q.insert({0,begin});
        while(q.size()){
            auto it=*q.begin();
            q.erase(it);
            string x=it.second;
            int step=it.first;
            if(x==end){
                return step+1;
            }
            for(int i=0; i<x.size(); i++){
                char original=x[i];
                for(char a='a'; a<='z'; a++){
                    x[i]=a;
                    if(s.find(x)!=s.end()){
                        s.erase(x);
                        q.insert({step+1,x});
                    }
                }
                x[i]=original;
            }
        }
        return 0;
    }
};