class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        map<int,int>m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto it: m){
            pq.push({it.second,it.first});
        }
        vector<int> ans;
        while(pq.size() && k--){
            int count=pq.top().first;
            int num=pq.top().second;
            ans.push_back(num);
            pq.pop();
        }
        return ans;
    }
};