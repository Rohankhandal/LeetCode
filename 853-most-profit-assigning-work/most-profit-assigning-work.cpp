class Solution {
public:
    bool static cmp(pair<int,int>&p1,pair<int,int>&p2)
    {
        if(p1.first==p2.first) return p1.second<p2.second;
        return p1.first>p2.first;
    }
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>v;
        for(int i=0;i<diff.size();i++)
        {
            v.push_back({profit[i],diff[i]});
        }
        sort(v.begin(),v.end(),cmp);
        int ans=0;
        for(int i=0;i<worker.size();i++)
        {
            int k=0;
            while( k < v.size() && v[k].second>worker[i])
            {
                k++;
                // cout<<"inside k"<<v[k].second<<endl;
            }
            int temp=worker[i];
            while(k < v.size() && temp>=v[k].second)
            {
                // cout<<"outside K"<<v[k].second<<endl;
                ans+=v[k].first;
                temp-=v[k].second;
                break;
            }
            // cout<<i<<" "<<ans<<endl;
        }
        return ans;
    }
};