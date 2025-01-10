class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        map<char,int>maxfreq;
        for(auto &s:words2)
        {
            map<char,int>mp;
            for(auto &it:s)
            {
                mp[it]++;
            }
            for(auto &it:mp)
            {
                maxfreq[it.first]=max(maxfreq[it.first],it.second);
            }
        }
        for(auto &it:maxfreq)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }

        for(auto &s:words1)
        {
            map<char,int>temp;
            for(auto &it:s)
            {
                temp[it]++;
            }

            if(temp.size()<maxfreq.size()) continue;

            bool isValid=true;
            for(auto &it:maxfreq)
            {
                if(it.second>temp[it.first])
                {
                    isValid=false;
                    break;
                }
            }
            if(isValid) ans.push_back(s);
        }
        return ans;
    }
};