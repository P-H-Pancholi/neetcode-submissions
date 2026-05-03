class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq_map;
        for(int i : nums){
            freq_map[i]++;
        }
        vector<vector<int>> freq_bucket(nums.size()+1, vector<int>{});
        for(auto it : freq_map){
            freq_bucket[it.second].push_back(it.first);
        }

        int i = 0;
        vector<int> res;
        while(i < k){
            for(int j = nums.size(); j >= 0; j--){
                for(int curr : freq_bucket[j]){
                    res.push_back(curr);
                    i++;
                    if(i == k){
                        return res;
                    }
                }
            }
        }
        return res;
    }
};
