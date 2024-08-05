class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        string ans="";
        unordered_map<string,int>mp;
        for(auto &str:arr)
        {
            mp[str]++;
        }   
        int count=0;
        for(auto &str:arr)
        {
            if(mp[str]==1) count++;
            if(count==k)
            {
                ans=str;
                break;
            }
        }
        return ans;
    }
};