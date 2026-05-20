class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        st.insert(n);
        while(n != 1){
            int temp = n, tot = 0;
            while(temp){
                tot += pow((temp%10), 2);
                temp /= 10;
            }
            if(st.find(tot) != st.end()) return false;
            st.insert(tot);
            n = tot;
        }
        return true;
    }
};
