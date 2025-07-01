class MinStack {
public:
    long mini = LONG_MAX;
    stack<long> st;
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        } else if (val > mini) {
            st.push(val);
        } else {
            
            st.push((long)2*val - mini);
            mini = val;
        }
    }

    void pop() {
        if (st.top() < mini) {
            mini = (long)2*mini - st.top();
        }
        st.pop();
    }

    int top() {
        if (st.top() < mini) {
            return mini;
        }
        return st.top();
    }

    int getMin() {
         return mini;
          }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */