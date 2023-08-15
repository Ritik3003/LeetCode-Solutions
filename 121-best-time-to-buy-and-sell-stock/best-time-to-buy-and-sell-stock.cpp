class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        int pre=prices[0];
        for(int i=1; i<n; i++){
            if(pre>prices[i]){
                pre=prices[i];
            }else{
                ans=max(ans,prices[i]-pre);
            }
        }
        return ans;
    }
};