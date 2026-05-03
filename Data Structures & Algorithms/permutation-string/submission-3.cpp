class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> ascii(26, 0);
        for(char c : s1){
            ascii[c-'a']++;
        }
        int start = 0, n = s1.size();
        while(start + n <= s2.size()){
            vector<int> local_ascii(26,0);
            int i = 0;
            while(i < n){
                local_ascii[s2[start+i]-'a']++;
                if(local_ascii[s2[start+i]-'a'] > ascii[s2[start+i]-'a']){
                    break;
                }
                i++;
            }
            if(i == n){
                return true;
            }
            start++;
        }
        return false;
    }
};
