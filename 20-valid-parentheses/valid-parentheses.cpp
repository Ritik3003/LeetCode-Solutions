class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }else{
                if(st.size()==0){
                    return false;
                }else if(s[i]==')' && st.top()=='('){
                    st.pop();
                }else if(s[i]==']' && st.top()=='['){
                    st.pop();
                }else if(s[i]=='}' && st.top()=='{'){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        if(st.size()){
            return false;
        }
        return true;
    }
};