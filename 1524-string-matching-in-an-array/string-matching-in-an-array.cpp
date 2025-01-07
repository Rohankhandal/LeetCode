class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>ans;
        set<string>st;
        for(auto s:words)
        {
            for(auto temp:words)
            {
                if(temp!=s && s.find(temp)!=string::npos)
                {
                    st.insert(temp);
                }
            }
        }
        for(auto &it:st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};