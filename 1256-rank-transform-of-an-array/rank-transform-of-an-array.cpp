class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n,0);
        map<int,int>mp;
        for(auto &it:arr)
        {
            mp[it]=1;
        }
        int rank=1;
        for(auto &it:mp)
        {
            it.second=rank;
            rank++;
        }
        for(int i=0;i<n;i++)
        {
            ans[i]=mp[arr[i]];
        }
        return ans;
    }
};