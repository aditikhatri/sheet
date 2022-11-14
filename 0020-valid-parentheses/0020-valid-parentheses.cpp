class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.length();
         for(int i=0;i<n;i++){
             if(s[i]=='{' or s[i]=='(' or s[i]=='[') st.push(s[i]);
             else{
                 if(st.empty()) return false;
                 char t=st.top();st.pop(); 
                 if((s[i]==']' and t=='[') or (s[i]==')' and t=='(') or
                    (s[i]=='}' and t=='{')) continue;
                 else return false;
             }
         }
           return (st.empty());
    }
};