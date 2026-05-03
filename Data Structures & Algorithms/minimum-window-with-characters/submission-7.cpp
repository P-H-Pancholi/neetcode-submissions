class Solution {
public:
    string minWindow(string s, string t) {
        if (t == "") {
            return "";
        }
        unordered_map<char, int> t_count;
        for(char c : t){
            t_count[c]++;
        }
        int have = 0, need = t_count.size();
        int start = 0, end = 0;
        string res = "";
        unordered_map<char,int> s_count;
        while(end < s.size()){
            if(t_count.find(s[end]) != t_count.end()){
                s_count[s[end]]++;
                if(t_count[s[end]] == s_count[s[end]]){
                    have++;
                }   
            }
            end++;
            while(have == need){
                if(res == "" || end-start < res.size()){
                    res = s.substr(start, end-start);
                }
                if(s_count.find(s[start]) != s_count.end()){
                    s_count[s[start]]--;
                    if(s_count[s[start]] < t_count[s[start]]){
                        have--;
                    }
                }
                start++;
            }
        }
        return res;
    }
};
/*
Note: Keep track od count have & need. 
if have == need, we have substring we need to find shorter,
so increment start until condition is false

if have != need, we do not have substring,
so increment end until we find substring
*/ 