class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> v(2051,0);
        for(int i=0; i<logs.size(); i++){
            v[logs[i][0]]++;
            v[logs[i][1]]--;
        }
        int ans=0;
        int maxi=INT_MIN;
        int population=0;
        for(int i=1950;i<2051; i++ ){
            population+=v[i];
            if(maxi<population){
                maxi=population;
                ans=i;
            }
        }
        return ans;
    }
};