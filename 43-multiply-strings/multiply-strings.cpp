class Solution {
public:
    string multiply(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        vector<int> nums(n1+n2,0);
        for(int i=n1-1; i>=0; i--){
            int k=i+n2;
            int carry=0;
            if(s1[i]!='-'){
                for(int j=n2-1;j>=0; j--){
                    int x=((s1[i]-'0')*(s2[j]-'0')+carry+nums[k]);
                    carry=x/10;
                    nums[k]=x%10;
                    k--;
                }
            }
            if(carry){
                nums[k]=carry;
            }
        }
        string ans="";
        for(int i=0; i<n1+n2; i++){
            ans+=to_string(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        for(int i=n1+n2-1; i>=0; i--){
            if(ans[i]=='0'){
                ans.pop_back();
            }else{
                break;
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans==""){
            return "0";
        }
        return ans;
    }
};