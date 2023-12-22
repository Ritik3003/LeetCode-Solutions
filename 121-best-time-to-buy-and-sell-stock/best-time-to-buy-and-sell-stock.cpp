class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        int pre=prices[0];
        for(int i=1; i<n; i++){
            if(prices[i]<pre){
                pre=prices[i];
            }
            ans=max(ans,prices[i]-pre);
        }
        return ans;
    }
};