class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> group;
        for(int i = 0; i < strs.size(); i++){
            string curr = strs[i];
            int j = 0;
            while(j < group.size()){
                string group_curr = group[j][0];
                if(group_curr.size() != curr.size()){
                    j++;
                    continue;
                }
                unordered_map<char, int> umap;
                int k = 0;
                while(k < curr.size()){
                    umap[curr[k]]++;
                    k++;
                }
                k = 0;
                while(k < group_curr.size()){
                    umap[group_curr[k]]--;
                    if( umap[group_curr[k]] < 0){
                        break;
                    }
                    k++;
                }
                if(k == group_curr.size()){
                    group[j].push_back(curr);
                    break;
                }
                j++;
            }
            if(j == group.size()){
                vector<string> temp = {curr};
                group.push_back(temp);
            }
        }
        return group;
    }
};
