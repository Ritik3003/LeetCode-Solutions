class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>, greater<int>> pq1, pq2;
        int i=0;
        int n=costs.size();
        int j=n-1;
        long long int ans=0;
        while(k--){
            while(pq1.size()<candidates && i<=j){
                pq1.push(costs[i++]);
            }
            while(pq2.size()<candidates && i<=j){
                pq2.push(costs[j--]);
            }
            int a=INT_MAX;
            int b=INT_MAX;
            if(pq1.size()){
                a=pq1.top();
            }
            if(pq2.size()){
                b=pq2.top();
            }
            if(a<=b){
                ans+=a;
                pq1.pop();
            }else{
                ans+=b;
                pq2.pop();
            }
        }
        return ans;
    }
};