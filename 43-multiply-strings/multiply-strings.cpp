class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.size();
        int n2=num2.size();
        vector<int> nums(n1+n2,0);
        for(int i=n1-1; i>=0; i--){
            int k=i+n2;
            int carry=0;
            if(num1[i]!='-'){
                for(int j=n2-1; j>=0; j--){
                    if(num2[j]!='-'){
                        int x=((num1[i]-'0')*(num2[j]-'0')+carry)+nums[k];
                        nums[k]=x%10;
                        carry=x/10;
                        k--;
                    }
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
        int count=0;
        if(num1[0]=='-'){
            count++;
        }
        if(num2[0]=='-'){
            count++;
        }
        if(count%2){
            ans+='-';
        }
        reverse(ans.begin(),ans.end());
        if(ans==""){
            return "0";
        }
        return ans;

    }
};