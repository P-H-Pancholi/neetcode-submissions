class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, maxLength = 0, end = 0;
        vector<int> ascii(256,0); 
        while(end < s.size()){
            while(start < end && ascii[s[end]] != 0){
                ascii[s[start]]--;
                start++;
            }
            ascii[s[end]]++;
            maxLength = max(maxLength, end-start+1);
            end++;
        }
        return maxLength;
    }
};
