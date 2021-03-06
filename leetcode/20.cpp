class Solution {
public:
    bool isValid(string s) {
        if(s[0]==')' or s[0]=='}' or s[0]==']') return false;
        stack<char> st;
        for(int i=0;i<s.length();i++){
          if(s[i]=='(' or s[i]=='{' or s[i]=='['){
              st.push(s[i]);
          }
            else{
                if(s[i]==')'){
                    if(st.empty()) return false;
                    if(st.top()=='(') st.pop();
                    else return false;
                }
                if(s[i]=='}'){
                    if(st.empty()) return false;
                    if(st.top()=='{') st.pop();
                    else return false;
                }
                if(s[i]==']'){
                    if(st.empty()) return false;
                    if(st.top()=='[') st.pop();
                    else return false;
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
};
