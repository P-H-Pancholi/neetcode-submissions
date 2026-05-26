class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for(int i : nums){
            umap[i]++;
        }
        vector<vector<int>> bucket(nums.size()+1);
        for(auto& it : umap){
            bucket[it.second].push_back(it.first);
        }
        vector<int> res;
        for(int i = nums.size(); i >= 0; i--){
            vector<int> curr = bucket[i];
            for(int j : curr){
                res.push_back(j);
                if(res.size() == k){
                    return res;
                }
            }
        }
        return res;
    }
};
