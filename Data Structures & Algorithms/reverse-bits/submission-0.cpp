class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int bit = 31;
        while(n){
            if(n%2){
                res += pow(2, bit);
            }
            bit--;
            n /= 2;
        }
        return res;
    }
};
