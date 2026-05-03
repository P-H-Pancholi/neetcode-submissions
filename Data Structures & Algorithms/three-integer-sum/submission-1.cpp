class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size()-1; i++){
            if(i > 0 && nums[i-1] == nums[i]){
                continue;
            }
            int start = i+1, end = nums.size()-1;
            while(end > start){
                int curr = nums[i] + nums[start] + nums[end];
                if(curr == 0){
                    ans.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                    while(nums[end] == nums[end+1]) end--;
                    while(nums[start] == nums[start-1]) start++;
                }else if(curr > 0){
                    end--;
                }else{
                    start++;
                }
            }
        }
        return ans;
    }
};
