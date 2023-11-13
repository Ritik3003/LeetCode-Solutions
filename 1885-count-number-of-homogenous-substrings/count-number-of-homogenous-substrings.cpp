class Solution {
public:
    int countHomogenous(string s) {
        int n=s.size();
        int count =1;
        long long int ans=0;
        int mod=1e9+7;
        int i=1;
        if(n==1){
            return 1;
        }
        char pre=s[0];
        while(i<n){
            while(i<n && pre==s[i]){
                i++;
                count++;
            }
            // cout<<pre<<" "<<count<<"\n";
            // i++;
            long long int x=((count)*1ll*((count+1)))/2;
            // cout<<x;
            ans+=x;
            ans=ans%mod;
            count=0;
            pre=s[i];
        }
        return ans;
    }
};