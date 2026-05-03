class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;

        while(end > start) {
            int end_ascii = s[end];
            int start_ascii = s[start];
            if(end_ascii >= 65 && end_ascii <= 90){
                end_ascii += 32;
            }

            if(start_ascii >= 65 && start_ascii <= 90){
                start_ascii += 32;
            }

            if(end_ascii < 97){
                if(!(end_ascii >= 48 && end_ascii <= 57)){
                    end--;
                    continue;
                }
            }else if(end_ascii > 122){
                    end--;
                    continue;
            }

            if(start_ascii < 97){
                if(!(start_ascii >= 48 && start_ascii <= 57)){
                    start++;
                    continue;
                }
            }else if(start_ascii > 122){
                    start++;
                    continue;
            }
            
            if(start_ascii != end_ascii){
                cout << start_ascii << " " << end_ascii << endl; 
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
