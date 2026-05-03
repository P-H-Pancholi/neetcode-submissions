class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for(string s : strs){
            encoded_string += to_string(s.size());
            encoded_string += '#';
            encoded_string += s;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_array;
        string curr = "";
        int i = 0;
        while(i < s.size()){
            string sizeOfStr = "";
            while(s[i] != '#'){
                sizeOfStr += s[i];
                i++;
            }
            int n = stoi(sizeOfStr);
            decoded_array.push_back(s.substr(i+1,n));
            i += (n+1);
        }
        return decoded_array;
    }
};
