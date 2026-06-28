class Solution {
public:
    int getSum(int a, int b) {
        int res = a ^ b;
        while(a & b){
            b = (a & b) << 1;
            a = res;
            res = a ^ b;
        }
        return res;
    }
};
