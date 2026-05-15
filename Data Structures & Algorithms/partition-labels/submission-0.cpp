class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> lastIndex;
        for(int i = 0; i < s.size(); i++){
            lastIndex[s[i]] = i;
        }
        vector<int> res;
        int i = 0;
        while(i < s.size()){
            int maxIdx = lastIndex[s[i]];
            if(maxIdx == i){
                res.push_back(1);
                i++;
            }else{
                int j = i+1;
                while(j < maxIdx){
                    if(lastIndex[s[j]] > maxIdx){
                        maxIdx = lastIndex[s[j]];
                    }
                    j++;
                }
                res.push_back(j-i+1);
                i = j+1;
            }
        }
        return res;
    }
};
