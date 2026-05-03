class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        vector<int> ascii_s(26, 0);
        vector<int> ascii_t(26, 0);

        for(char c : s){
            ascii_s[c-'a']++;
        }
        for(char c : t){
            ascii_t[c-'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(ascii_s[i] != ascii_t[i]){
                return false;
            }
        }
        return true;
    }
};
