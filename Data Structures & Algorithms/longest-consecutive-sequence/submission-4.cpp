class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> umap;
        for(int i : nums){
            umap[i] = true;
        }
        int res = 0;
        for(int i : nums){
            if(umap[i-1]){
                continue;
            }
            int curr = i;
            while(umap[curr]){
                curr++;
            }
            res = max(res, curr-i);
        }
        return res;
    }
};
