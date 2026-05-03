class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int i = 0, buff = s1.size();
        vector<int> global(26, 0);
        for(char c : s1){
            global[c-'a']++;
        }
        while(i + buff <= s2.size()){
            vector<int> local(26,0);
            for(int j = i; j < i+buff; j++){
                local[s2[j]-'a']++;
            }
            bool equal = true;
            for(int j = 0; j < buff; j++){
                if(local[s2[i+j]-'a'] != global[s2[i+j]-'a']){
                    if(global[s2[i+j]-'a'] == 0){
                        i = i+j;
                    }
                    equal = false;
                    break;
                }
            }
            if(equal){
                return true;
            }
            i++;
        }
        return false;
    }
};
