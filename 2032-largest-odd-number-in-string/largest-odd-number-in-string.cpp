class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        string x="";
        string ans="";
        for(int i=0; i<n; i++){
            int a=num[i]-'0';
            if(a%2==1){
                x+=num[i];
                ans=x;
            }else{
                x+=num[i];
            }
        }
        return ans;
    }
};