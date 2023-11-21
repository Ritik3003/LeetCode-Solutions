class Solution {
public:
int solve(int num){
    int ans=0;
    while(num){
        int rem=num%10;
        ans=ans*10+rem;
        num/=10;
    }
    return ans;
}

    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n,0);
        for(int i=0; i<n; i++){
            v[i]=nums[i]-solve(nums[i]);
        }
        map<int,int> m;
        // int ans=0;
        for(int i=0; i<n; i++){
            m[v[i]]++;
        }
        long long int ans=0;
        int mod=1e9+7;
        for(auto it: m){
            long long int count=(it.second*1ll)*((it.second)*1ll-1)/2;
            ans+=count;
            ans=ans%mod;
        }
        return ans%mod;
    }
};