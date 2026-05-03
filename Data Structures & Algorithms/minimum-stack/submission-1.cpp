class MinStack {
public:
    stack<int> st;
    stack<int> min_st;
    MinStack() {    
        this->min_st.push(INT_MAX);
    }
    
    void push(int val) {
        this->st.push(val);
        this->min_st.push(min(val,min_st.top()));
    }
    
    void pop() {
        this->st.pop();
        this->min_st.pop();
    }
    
    int top() {
        return this->st.top();
    }
    
    int getMin() {
        return this->min_st.top();
    }
};
