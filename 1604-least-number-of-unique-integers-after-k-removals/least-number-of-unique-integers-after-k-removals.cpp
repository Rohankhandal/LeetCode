class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        for(auto &it:arr)
        {
            mp[it]++;
        }
        vector<pair<int,int>>v;
        for(auto &it:mp)
        {
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end());
        for(auto &it:v)
        {
            if(k==0)
            break;
            int freq=it.first;
            it.first-=k;
            k=abs(k-freq);

        }
        int ans=0;
        for(auto &it:v)
        {
            if(it.first>0)
            {
                ans++;
            }
        }
        return ans;

    }
};