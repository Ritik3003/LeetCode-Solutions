class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n=s.size();
        int left=0;
        int count=0;
        int ans=0;
        for(int i=0; i<n; i++){
            if(s[i]=='F'){
                count++;
            }
            while(count>k){
                if(s[left]=='F'){
                    count--;
                }
                left++;
            }
            ans=max(ans,i-left+1);
        }
        left=0;
        count=0;
        for(int i=0; i<n; i++){
            if(s[i]=='T'){
                count++;
            }
            while(count>k){
                if(s[left]=='T'){
                    count--;
                }
                left++;
            }
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};