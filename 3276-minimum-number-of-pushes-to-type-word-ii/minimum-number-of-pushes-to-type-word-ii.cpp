class Solution {
public:
    int minimumPushes(string word) {
      
        unordered_map<char,int>mp;
        for(auto &it:word)
        {
            mp[it]++;
        }

        // vector<pair<char,int>>arr;
        // for(auto&it:mp)
        // {
        //     arr.push_back({it.first,it.second});
        // }
        // auto cmp=[&](pair<char,int>&p1,pair<char,int>&p2)
        // {
        //     return p1.second>p2.second;
        // };

        // sort(arr.begin(),arr.end(),cmp);


        priority_queue<int>pq;
        for(auto &it:mp)
        {
            int freq=it.second;
            pq.push(freq);
        }

        int cnt=1;
        int ans=0;
        int value=1;
        while(!pq.empty())
        {
            int freq=pq.top();
            pq.pop();
            ans+=(freq*value);
            cnt++;
            if(cnt==9)
            {
                cnt=1;
                value++;
            }
        }
        return ans;
    }
};