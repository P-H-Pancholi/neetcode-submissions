class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        st.push(0);
        vector<int> res(temperatures.size(), 0);
        for(int i = 1; i < temperatures.size(); i++) {
            while (!st.empty() && (temperatures[st.top()] < temperatures[i])){
                int curr = st.top();
                res[curr] = i-curr;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
