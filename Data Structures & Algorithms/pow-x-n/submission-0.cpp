class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        bool isNeg = n < 0;
        n = abs(n-0);
        while(n){
            res *= x;
            n--;
        }
        if(isNeg){
            res = 1.0/res;
        }
        return res;
    }
};
