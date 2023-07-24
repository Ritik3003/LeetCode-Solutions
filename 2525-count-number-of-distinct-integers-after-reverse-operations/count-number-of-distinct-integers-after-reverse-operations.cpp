class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<string> s;
        int n=nums.size();
        for(int i=0; i<n; i++){
            string x=to_string(nums[i]);
            s.insert(x);
            int a=x.size();
            while(x[a-1]=='0'){
                x.pop_back();
                a--;
            }
            reverse(x.begin(),x.end());
            s.insert(x);
        }
        return s.size();
    }
};