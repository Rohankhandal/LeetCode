class StockSpanner {
public:
    int span=1;
    stack<pair<int,int>>st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int time=1;
        if(st.empty())
        {
            st.push({price,1});
        }
        else
        {
            while(!st.empty() && st.top().first<=price)
            {
                time+=st.top().second;
                st.pop();
            }
            st.push({price,time});
        }
        return time;    
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */