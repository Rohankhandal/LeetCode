class MinStack {
public:
    vector<pair<int,int>>st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push_back({val,val});
        }
        else
        {
            int minVal=st.back().second;
            cout<<minVal<<endl;
            minVal=min(val,minVal);
            st.push_back({val,minVal});
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
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