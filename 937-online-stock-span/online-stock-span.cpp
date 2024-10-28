class StockSpanner {
private:
    // Stack pair stores {price, span}
    stack<pair<int, int>> st;
    
public:
    StockSpanner() {}
    
    int next(int price) {
        int span = 1;
        
        // Pop elements from stack while they are smaller/equal to current price
        // Add their spans to current span
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        
        // Push current price and its span
        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */