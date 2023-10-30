class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        // priority_queue<pair<int,int>> pq;
        int n=arr.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0; i<n; i++){
            int count=0;
            int x=arr[i];
            while(arr[i]){
                if((arr[i] & 1)==1){
                    count++;
                }
                arr[i]=arr[i]/2;
            }
            pq.push({count,x});
        }
        vector<int> ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};