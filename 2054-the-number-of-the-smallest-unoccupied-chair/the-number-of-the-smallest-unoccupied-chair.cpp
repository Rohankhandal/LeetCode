class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<pair<pair<int,int>,int>>v;
        int n=times.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({{times[i][0],times[i][1]},i});
        }
        sort(v.begin(),v.end());
        // for(auto &it:v)
        // {
        //     cout<<it.first.first<<" "<<it.first.second<<endl;
        // }

        vector<pair<int,int>>chair(n);
        for(auto &it:chair) it={0,0};
        for(auto &it:v)
        {
            int start=it.first.first;
            int leave=it.first.second;
            int idx=it.second;
            for(int i=0;i<n;i++)
            {
                if(chair[i].first<=start)
                {
                    chair[i].first=leave;
                    chair[i].second=idx;
                    break;
                }
            }
            if(idx==targetFriend)
            {
                 for(int i=0;i<n;i++)
                {
                    if(chair[i].second==idx)
                    {
                        return i;
                    }
                }
            }
        }
        return 0;
    }
};