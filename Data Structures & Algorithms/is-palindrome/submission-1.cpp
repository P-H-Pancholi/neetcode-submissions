class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size()-1;
        while(start < end){
            if((s[start] < 'a' || s[start] > 'z') && 
            (s[start] < 'A' || s[start] > 'Z') &&
            (s[start] < '0' || s[start] > '9')){
                start++;
                continue;
            }

            if((s[end] < 'a' || s[end] > 'z') && 
            (s[end] < 'A' || s[end] > 'Z') &&
            (s[end] < '0' || s[end] > '9')){
                end--;
                continue;
            }

            if(tolower(s[start]) != tolower(s[end])){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
