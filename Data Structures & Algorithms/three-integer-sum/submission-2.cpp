class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++){
            if(i != 0 && nums[i] == nums[i-1]){
                continue;
            }
            int start = i+1, end = nums.size()-1;
            while(start < end){
                int curr = nums[i] + nums[start] + nums[end];
                if(curr == 0){
                    res.push_back({nums[i], nums[start], nums[end]});
                    
                    start++;
                    while(start < end && nums[start] == nums[start-1]){
                        start++;
                    }

                    end--;
                    while(start < end && nums[end] == nums[end+1]){
                        end--;
                    }
                }else if(curr > 0){
                    end--;
                    while(start < end && nums[end] == nums[end+1]){
                        end--;
                    }
                }else{
                    start++;
                    while(start < end && nums[start] == nums[start-1]){
                        start++;
                    }
                }
            }
        }
        return res;
    }
};
