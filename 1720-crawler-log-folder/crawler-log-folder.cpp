class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>st;
        for(auto &str:logs)
        {
            if(str=="../")
            {
                // cout<<st.top()<<endl;
                if(!st.empty())
                    st.pop();
            }
            else if(str=="./")
            {
                continue;
            }
            else
            {
                st.push(str.substr(0,str.length()-1));
            }
        }
        return st.size();
    }
};