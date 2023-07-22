class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int> v;
        for(int i=0; i<n-1; i++){
            v.push_back(weights[i]+weights[i+1]);
        }
        sort(v.begin(),v.end());
        long long int maxi=0;
        long long int mini=0;
        for(int i=0; i<k-1; i++){
            mini+=v[i];
            maxi+=v[n-2-i];
        }
        return maxi-mini;
    }
};