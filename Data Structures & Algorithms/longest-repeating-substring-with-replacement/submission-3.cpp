class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, maxLength = 0;
        vector<int> freq_map(26,0);
        freq_map[s[0]-'A']++;
        while(right < s.size()){
            int max_freq = 0;
            for(int i : freq_map){
                max_freq = max(i, max_freq);
            }
            if((right-left+1)-max_freq <= k){
                maxLength = max(maxLength, right-left+1);
                right++;
                freq_map[s[right]-'A']++;
            }else{
                freq_map[s[left]-'A']--;
                left++;
            }
        }
        return maxLength;
    }
};
