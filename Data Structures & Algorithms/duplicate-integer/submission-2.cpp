class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> freq_map;
        for(int i : nums){
            if (freq_map[i]){
                return true;
            }
            freq_map[i] = true;
        }
        return false;
    }
};