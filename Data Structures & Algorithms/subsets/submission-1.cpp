class Solution {
public:
    void backtrack(int index, vector<int> curr, vector<int>& nums,vector<vector<int>> &res){
        res.push_back(curr);
        while(index < nums.size()){
            curr.push_back(nums[index]);
            backtrack(index+1, curr, nums, res);
            curr.pop_back();
            index++;
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(0,{},nums,res);
        return res;
    }
};
