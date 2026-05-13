class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int,int>> vec(nums.size()+1);
        vec[0][0] = 1;
        for(int i = 1; i <= nums.size(); i++){
            for(auto it : vec[i-1]){
                vec[i][it.first+nums[i-1]] += it.second;
                vec[i][it.first-nums[i-1]] += it.second; 
            }
        }
        return vec[nums.size()][target];
    }
};
