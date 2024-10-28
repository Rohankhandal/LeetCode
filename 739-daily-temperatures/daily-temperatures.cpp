class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans;
        stack<pair<int,int>>st;
        int n=temperatures.size();
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                ans.push_back(0);
                st.push({temperatures[i],1});
            }
            else
            {
                int cnt=1;
                while(!st.empty() && st.top().first<=temperatures[i])
                {
                    cnt+=st.top().second;
                    st.pop();
                }
                if(st.empty())
                {
                    ans.push_back(0);
                    st.push({temperatures[i],1});
                }
                else
                {
                    ans.push_back(cnt);
                    //push the element
                st.push({temperatures[i],cnt});
                }
                
                
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};