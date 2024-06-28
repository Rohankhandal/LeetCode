class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<long long ,long long >mp;
        for(auto &r:roads)
        {
            long long  a=r[0];
            long long  b=r[1];
            mp[a]++;
            mp[b]++;
        }
        priority_queue<pair<long long ,long long >>pq;
        for(auto &it:mp)
        {
            pq.push({it.second,it.first});
        }

        unordered_map<long long ,long long >imp;
        long long  k=n;
        while(!pq.empty())
        {
            pair<long long ,long long >p=pq.top();
            pq.pop();
            imp[p.second]=k;
            k--;
        }
        long long  ans=0;
        
        for(auto &it:mp)
        {
            ans+=(imp[it.first]*mp[it.first]);
        }

        return ans;
    }
};