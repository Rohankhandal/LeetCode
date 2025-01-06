class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>ans(n,0);
        unordered_map<int,bool>mp;
        for(int i=0;i<n;i++)
        {
            if(boxes[i]=='1') mp[i]=true;
        }

        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(auto &it:mp)
            {
                if(it.first!=i)
                    cnt+=(abs(it.first-i));
            }
            ans[i]=cnt;
        }
        return ans;
    }
};