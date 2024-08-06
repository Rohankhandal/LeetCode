class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        cout<<n<<endl;
        unordered_map<char,int>mp;
        for(auto &it:word)
        {
            mp[it]++;
        }
        vector<pair<char,int>>arr;
        for(auto&it:mp)
        {
            arr.push_back({it.first,it.second});
        }
        auto cmp=[&](pair<char,int>&p1,pair<char,int>&p2)
        {
            return p1.second>p2.second;
        };

        sort(arr.begin(),arr.end(),cmp);

        for(auto &t:arr)
        {
            cout<<t.first<<" "<<t.second<<endl;
        }
        cout<<endl;
        int cnt=1;
        int ans=0;
        int value=1;
        for(auto &it:arr)
        {
            int ele=it.first;
            int freq=it.second;

            ans+=(freq*value);
            cout<<(char)ele<<" "<<value<<endl;
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