class Solution {
public:
    bool checkValidString(string s) {
        stack<int> paren;
        stack<int> stars;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                paren.push(i);
            }
            if(s[i] == ')'){
                if(paren.empty()){
                    if(stars.empty()){
                        return false;
                    }else{
                        stars.pop();
                    }
                }else{
                    paren.pop();
                }
            }
            if(s[i] == '*'){
                stars.push(i);
            }
        }
        while(paren.size()){
            if(stars.empty()) return false;
            if(paren.top() > stars.top()) return false;
            paren.pop();
            stars.pop();
        }
        return true;
    }
};
