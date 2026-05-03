class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for(int i = 0; i < nums.size(); i++){
            if(umap[target-nums[i]] != 0){
                int idx1 = umap[target-nums[i]];
                if(idx1 == -1){
                    idx1 = 0;
                }
                vector<int> index = {idx1, i};
                return index;
            }
            if(i == 0){
                umap[nums[i]] = -1;
            }else{
                umap[nums[i]] = i;
            }
        }

    }
};
