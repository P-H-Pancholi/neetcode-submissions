class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, maxLength = 0;
        vector<int> freq_map(26,0);
        while(right < s.size()){
            freq_map[s[right]-'A']++;
            int max_freq = 0;
            for(int i : freq_map){
                max_freq = max(i, max_freq);
            }

            while((right-left+1) - max_freq > k){
                freq_map[s[left]-'A']--;
                left++;
            }
            maxLength = max(right-left+1, maxLength);
            right++;
        }
        return maxLength;
    }
};
