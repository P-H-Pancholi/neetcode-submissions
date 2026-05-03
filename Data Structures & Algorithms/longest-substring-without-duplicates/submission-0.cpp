class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> ascii(256, -1);
        int i = 0;
        int maxLength = INT_MIN, currLength = 0;
        while(i < s.size()){
            if(ascii[s[i]] == -1){
                ascii[s[i]] = i;
                currLength++;
                i++;
            }else{
                maxLength = max(maxLength, currLength);
                currLength = 0;
                i = ascii[s[i]]+1;
                fill(ascii.begin(), ascii.end(), -1);
            }
        }
        return max(maxLength, currLength);
    }
};
