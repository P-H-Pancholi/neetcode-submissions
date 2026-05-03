class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq_map;
        for(int i = 0; i < nums.size(); i++){
            freq_map[nums[i]]++;
        }
        vector<vector<int>> buckets(nums.size()+1);
        for(auto it : freq_map){
            buckets[it.second].push_back(it.first);
        }
        vector<int> ans;
        for(int i = nums.size(); i >= 0; i--){
            for(int j : buckets[i]){
                ans.push_back(j);
                if(ans.size() == k){
                    return ans;
                }
            }

        }
        return ans;
    }
};
