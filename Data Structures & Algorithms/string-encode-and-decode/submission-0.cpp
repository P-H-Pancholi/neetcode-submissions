class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";
        for(int i = 0; i < strs.size(); i++) {
            encoded_string += to_string(strs[i].size());
            encoded_string += "#";
            encoded_string += strs[i];
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_list;
        int i = 0;
        while(i < s.size()){
            string length = "";
            int j = i;
            while(s[j] != '#'){
                length += s[j];
                j++;
            }
            int length_num = stoi(length);
            j++;
            int k = 0;
            string curr = "";
            while(k < length_num){
                curr += s[j+k];
                k++;
            }
            decoded_list.push_back(curr);
            i = j+k;
        }
        return decoded_list;
    }
};
