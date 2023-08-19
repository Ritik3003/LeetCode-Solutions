class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n=reward1.size();
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            pq.push(reward1[i]-reward2[i]);
        }
        int ans=accumulate(reward2.begin(),reward2.end(),0);
        for(int i=0; i<k; i++){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};