class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        if(v.size()<=1){
            return 0;
        }
        int ans=0;
        for(int i=0; i<v.size()-1; i++){
            if(v[i][1]>v[i+1][0]){
                ans++;
                v[i+1][1]=min(v[i][1], v[i+1][1]);
            }
        }
        return ans;
    }
};