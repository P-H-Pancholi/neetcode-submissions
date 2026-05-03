class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }else{
                if(st.size() == 0){
                    return false;
                }
                char top = st.top();
                if(top == '(' && c != ')'){
                    return false;
                }
                if(top == '{' && c != '}'){
                    return false;
                }
                if(top == '[' && c != ']'){
                    return false;
                }
                st.pop();
            }
        }
        return (st.size() == 0);
    }
};
