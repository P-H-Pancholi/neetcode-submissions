class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }

        int consec_size = 0;
        for(int i = 0; i < nums.size(); i++){
            if(map[nums[i]-1] == 0){
                int curr_length = 1;
                int curr = nums[i] + 1;
                while(map[curr] > 0){
                    curr_length++;
                    curr++;
                }
                if(curr_length > consec_size) {
                    consec_size = curr_length;
                }
            }
        }
        return consec_size;
    }
};
