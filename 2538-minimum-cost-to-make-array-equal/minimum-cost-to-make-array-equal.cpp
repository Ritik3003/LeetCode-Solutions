class Solution {
public:
long long int solve(vector<int>&nums,vector<int>&cost, long long int median){
    long long int ans=0;
    for(int i=0; i<nums.size(); i++){
        ans=ans+abs(1ll*nums[i]-median)*(1ll*cost[i]);
    }
    return ans;
}


    long long minCost(vector<int>& nums, vector<int>& cost) {
        // long long int sum=accumulate(cost.begin(),cost.end(),0);
        long long int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum=sum+cost[i];
        }
        long long int total=0;
        long long int median=0;
        vector<pair<long long int,long long int>> v;
        for(int i=0; i<nums.size(); i++){
            v.push_back({nums[i],cost[i]});
        }
        sort(v.begin(),v.end());
        int n=nums.size();
        int i=0;
        while(total<(sum+1)/2 && i<n){
            total=total+1ll*v[i].second;
            median=v[i].first;
            i++;
        }
        return solve(nums,cost,median);
    }
};