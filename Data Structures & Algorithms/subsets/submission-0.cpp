class Solution {
public:
    void backtrack(int index, vector<int> curr, vector<int>& nums,vector<vector<int>> &res){
        curr.push_back(nums[index]);
        res.push_back(curr);
        if(index+1 < nums.size()){
            backtrack(index+1, curr, nums, res);
            if(curr.size() > 0){
                backtrack(index+1, vector<int>(curr.begin(), curr.end()-1), nums, res);
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        backtrack(0,{},nums,res);
        return res;
    }
};
