class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        for(int i = 0; i < nums.size(); i++){
            freq_map[nums[i]]++;
        }
        vector<int> k_freq;
        
        vector<vector<int>> freq_ord_map(nums.size()+1);
        for(auto it: freq_map){
            cout << it.first << " " << it.second << endl;
            freq_ord_map[it.second].push_back(it.first);
        }
        int count_k = 0;
        for(int i = nums.size(); i >= 0; i--){
            for(int j = 0; j < freq_ord_map[i].size(); j++){
                k_freq.push_back(freq_ord_map[i][j]);
                count_k++;
                if(count_k == k){
                    return k_freq;
                }
            }
        }
        return k_freq;
    }
};
