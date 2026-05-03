class Solution {
public:
    void backtrack(vector<string> &res, vector<vector<char>> &mapChars, string digits, string &curr, int index){
        if(index == digits.size()){
            res.push_back(curr);
            return;
        }
        for(char c :  mapChars[digits[index] - '2']){
            curr.push_back(c);
            backtrack(res, mapChars, digits, curr, index+1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return {};
        }
        vector<vector<char>> mapChars(8);
        mapChars[0] = {'a', 'b', 'c'};
        mapChars[1] = {'d', 'e', 'f'};
        mapChars[2] = {'g', 'h', 'i'};
        mapChars[3] = {'j', 'k', 'l'};
        mapChars[4] = {'m', 'n', 'o'};
        mapChars[5] = {'p', 'q', 'r', 's'};
        mapChars[6] = {'t', 'u', 'v'};
        mapChars[7] = {'w', 'x', 'y', 'z'};
        vector<string> res;
        string curr = "";
        backtrack(res, mapChars, digits, curr, 0);
        return res;
    }
};
