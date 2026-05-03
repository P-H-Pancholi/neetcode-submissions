class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int start = 0, end = 0, maxLength = 0;
        freq[s[0]-'A'] = 1;
        while(end < s.size()){
            int maxFreq = 0;
            for(int i : freq){
                maxFreq = max(i, maxFreq);
            }
            // Number of character we need to replace will be 
            // lenght of window - max_freq
            int noOfCharToReplace = (end-start+1)-maxFreq;
            if(noOfCharToReplace <= k){
                maxLength = max(end-start+1, maxLength);
                end++;
                freq[s[end]-'A']++;
            }else{
                freq[s[start]-'A']--;
                start++;
            }
        }
        return maxLength;
    }
};
