class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        for(int i=1;i<=n;i++)
        {
            string s=to_string(i);
            int sum=0;
            for(auto &num:s){
                sum+=(num-'0');
            }
            mp[sum]++;
        }

        int maxSize=INT_MIN;
        for(auto &it:mp)
        {
            if(it.second>maxSize)
            {
                maxSize=it.second;
            }
        }

        int ans=0;
         for(auto &it:mp)
        {
            if(it.second==maxSize)
            {
                ans++;
            }
        }
        return ans;
    }
};