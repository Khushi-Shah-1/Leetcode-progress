class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else if(ch==')'){
                if(st.empty()) return false;
                char ch2=st.top();
                if(ch2=='('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(ch=='}' ){
                if(st.empty()) return false;
                char ch2=st.top();
                if(ch2=='{'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else if(ch==']' ){
                if(st.empty()) return false;
                char ch2=st.top();
                if(ch2=='['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
};