class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans=0;
        unordered_map<int,int>mp;

        int l=0,r=0;
        while(r<n)
        {
            mp[fruits[r]]++;

            while(l<=r && mp.size()>2)
            {
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                l++;
            }


            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};