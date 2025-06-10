class Solution {
public:
    int maxDifference(string s) {
     int n=s.size();

     unordered_map<char,int>mp;
     for(auto &it:s)
     {
        mp[it]++;
     }   
    int ans=INT_MIN;
     for(auto &it:mp)
     {
        if(it.second&1) //if odd
        for(auto &i:mp)
        {
            if((i.second&1)==0) //if even
            {
                ans=max(ans,it.second-i.second);
            }
        }
     }
     return ans;
    }
};