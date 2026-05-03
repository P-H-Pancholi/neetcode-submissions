class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> exists;
        for(int i : nums){
            exists.insert(i);
        }
        int maxLen = 0;
        for(int i : exists){
            if(exists.find(i-1) == exists.end()){
                int currLen = 1, j = i+1;
                while(exists.find(j) != exists.end()){
                    currLen++;
                    j++;
                }
                maxLen = max(maxLen, currLen);
            }
        }
        return maxLen;
    }
};
