class MinStack {
private:
    stack<int> st;
    stack<int> min_st;
public:
    MinStack() {
        min_st.push(INT_MAX);
    }
    
    void push(int val) {
        st.push(val);
        if(val <= min_st.top()){
            min_st.push(val);
        }
    }
    
    void pop() {
        if(st.top() == min_st.top()){
            min_st.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
