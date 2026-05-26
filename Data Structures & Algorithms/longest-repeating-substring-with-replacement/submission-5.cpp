class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq_map(26,0);
        int start = 0, end = 0, res = 0;
        while(end < s.size()){
            freq_map[s[end]-'A']++;
            int max_freq = 0;
            for(int i : freq_map){
                max_freq = max(max_freq,i);
            }
            while((end-start+1)-max_freq > k ){
                freq_map[s[start]-'A']--;
                start++;
            }
            res = max(res, end-start+1);
            end++;
        }
        return res;
    }
};
