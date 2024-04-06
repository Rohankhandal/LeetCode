class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;  //we insert index of open bracket instead of bracket for recognise at last that which
        //openbracket is not balanced
        unordered_set<int>mp;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(st.empty())
                {
                    mp.insert(i);
                }
                else
                {
                    st.pop();
                }
            }

        }

        //now insert all remaing index of stack into unordered set
        while(!st.empty())
        {
            mp.insert(st.top());
            st.pop();
        }

        string ans;
        for(int i=0;i<n;i++)
        {
            if(mp.find(i)==mp.end())
            {
                ans.push_back(s[i]);
            }
        }
        return ans;

    }
};