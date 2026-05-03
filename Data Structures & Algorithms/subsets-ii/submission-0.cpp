class Solution {
public:
    void backtrack(vector<int> &nums, vector<vector<int>> &res, vector<int> curr, int index){
        res.push_back(curr);
        for(int i = index; i < nums.size(); i++){
            if(i > index && nums[i] == nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            backtrack(nums, res, curr, i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        backtrack(nums, res, {}, 0);
        return res;
    }
};
