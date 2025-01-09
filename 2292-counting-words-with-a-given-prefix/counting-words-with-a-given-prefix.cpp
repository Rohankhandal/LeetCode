class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int cnt=0;
        for(auto &str:words)
        {
            int j;
            for(j=0;j<pref.size();j++)
            {
                if(str[j]!=pref[j])
                {
                    break;
                }
            }
            if(j==pref.size()) cnt++;
        }
        return cnt;
    }
};