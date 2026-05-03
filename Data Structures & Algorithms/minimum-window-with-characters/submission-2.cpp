class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> global(256,0);
        for(char c : t){
            global[c]++;
        }
        int start=0;
        string res = "";
        while(start + t.size() <= s.size()){
            if(global[s[start]] == 0){
                start++;
                continue;
            }
            vector<int> local(256,0);
            for(int j = start; j < s.size(); j++){
                local[s[j]]++;
                bool isSubStr = true;
                for(int k = 0; k < 256; k++){
                    if(global[k] != 0 && local[k] < global[k]){
                        isSubStr = false;
                    }
                }
                if(isSubStr){    
                    if(res=="" || res.size() > j-start+1){
                        res = s.substr(start,j-start+1);
                        break;
                    }
                }
            }
            start++;
        }
        return res;
    }
};
