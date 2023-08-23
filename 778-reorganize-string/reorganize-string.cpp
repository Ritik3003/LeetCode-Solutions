class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> m;
        int n=s.size();
        for(int i=0; i<n; i++){
            m[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it: m){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(pq.size()>=2){
            auto it1=pq.top();
            pq.pop();
            auto it2=pq.top();
            pq.pop();
            ans+=it1.second;
            ans+=it2.second;
            if(--it1.first>0){
                pq.push({it1.first,it1.second});
            }
            if(--it2.first>0){
                pq.push({it2.first,it2.second});
            }
        }
        if(pq.size()){
            auto it=pq.top();
            if(it.first>1){
                return "";
            }
            pq.pop();
            ans+=it.second;
        }
        return ans;
    }
};