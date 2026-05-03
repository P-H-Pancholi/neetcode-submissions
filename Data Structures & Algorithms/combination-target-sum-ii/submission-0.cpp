class Solution {
public:
    void backtrack(vector<int> &nums, vector<vector<int>> &res, 
        vector<int> curr, int currSum, int target, int index){
        if(currSum == target){
            res.push_back(curr);
            return;
        }
        if(currSum > target){
            return;
        }
        for(int i = index+1; i < nums.size(); i++){
            if(i > index+1 && nums[i] == nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            backtrack(nums, res, curr, currSum+nums[i], target, i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, res, {}, 0, target, -1);
        return res;
    }
};
