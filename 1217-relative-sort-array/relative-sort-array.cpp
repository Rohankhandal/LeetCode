class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        for(auto &it:arr1)
        {
            mp[it]++;
        }
        vector<int>ans;
        for(auto &it:arr2)
        {
            if(mp.find(it)!=mp.end())
            {
                for(int i=0;i<mp[it];i++)
                {
                    ans.push_back(it);
                }
                mp.erase(it);
            }
        }
        for(auto &it:mp)
        {
            for(int i=0;i<it.second;i++)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};