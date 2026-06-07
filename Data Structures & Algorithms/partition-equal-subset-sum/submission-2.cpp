class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i : nums){
            totalSum += i;
        }
        if(totalSum % 2 == 1) return false;
        int target = totalSum/2;
        unordered_set<int> st = {0};
        for(int i = nums.size()-1
        ; i >= 0; i--){
            unordered_set<int> next_st;
            for(int j : st){
                int curr = nums[i] + j;
                if(curr == target) return true;
                next_st.insert(curr);
                next_st.insert(j);
            }
            st = next_st;
        }
        return false;
    }
};
