class Solution {
public:
    void backtrack(vector<vector<int>> &res, vector<int> curr, vector<int>& nums, vector<bool> &mp){
        if(curr.size() == nums.size()){
            res.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(mp[i]){
                continue;
            }
            mp[i] = true;
            curr.push_back(nums[i]);
            backtrack(res, curr, nums, mp);
            curr.pop_back();
            mp[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> mp(nums.size(), false);
        vector<vector<int>> res;
        backtrack(res, {}, nums, mp);
        return res;
    }
};

