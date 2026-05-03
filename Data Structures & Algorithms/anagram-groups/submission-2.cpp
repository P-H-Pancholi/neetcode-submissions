class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> map;
        vector<vector<string>> grouped;
        for(int i = 0; i < strs.size(); i++) {
            vector<int> ascii(26, 0);
            for(char c : strs[i]){
                ascii[(int)c-97]++;
            }
            bool g_found = false;
            for(int j = 0; j < map.size(); j++){
                bool l_found = true;
                for(int k = 0; k < 26; k++){
                    if(map[j][k] != ascii[k]){
                        l_found = false;
                        break;
                    }
                }
                if(l_found){
                    g_found=true;
                    grouped[j].push_back(strs[i]);
                    break;
                }
            }
            if(g_found == false){
                vector<string> temp;
                temp.push_back(strs[i]);
                map.push_back(ascii);
                grouped.push_back(temp);
            }
        }
        return grouped;
    }
};
