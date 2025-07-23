class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n=s.size();
        string fString=(x>y)?"ab":"ba";
        string sString=(x>y)?"ba":"ab";
        int fHigh=(x>y)?x:y;
        int sHigh=(x>y)?y:x;
        int ans=0;
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            if(!st.empty() && st.top()==fString[0] && s[i]==fString[1])
            {
                st.pop();
                ans+=fHigh;
            }
            else st.push(s[i]);
        }
        string temp="";
        while(!st.empty())
        {
            temp+=st.top();
            st.pop();
        }

        reverse(temp.begin(),temp.end());

         for(int i=0;i<temp.size();i++)
        {
            if(!st.empty() && st.top()==sString[0] && temp[i]==sString[1])
            {
                st.pop();
                ans+=sHigh;
            }
            else st.push(temp[i]);
        }

        return ans;
    }
};