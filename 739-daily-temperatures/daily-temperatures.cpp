class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int n=temperatures.size();
        vector<int>result(n);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && temperatures[i]>=temperatures[st.top()])
            {
                st.pop();
            }

            //if stack is empty , no element is greater than 
            if(st.empty())
            {
                result[i]=0;
            }
            else
            {
                result[i]=st.top()-i;
            }
            st.push(i);
        }
        return result;
    }
};