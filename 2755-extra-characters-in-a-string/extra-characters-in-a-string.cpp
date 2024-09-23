class Solution {
public:
    int solve(int i,string s,unordered_map<string,int>&mp, vector<int>&dp)
    {
        if(i>=s.size())
        {
            return 0;
        }

        if(dp[i]!=-1) return dp[i];

        int op1=INT_MAX,op2=INT_MAX;
        for(int l=1;l<=s.size()-i;l++)
        {
            string temp=s.substr(i,l);
            if(mp.find(temp)!=mp.end())
            {
                op1=min(op1,solve(i+l,s,mp,dp));
            }
            else
            {
                op2=min(op2,l+solve(i+l,s,mp,dp));  //not match
            }
        }
        return dp[i]=min(op1,op2);
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int>mp;
        for(auto &it:dictionary)
        {
            mp[it]++;
        }
        vector<int>dp(s.size(),-1);
        return solve(0,s,mp,dp);
    }
};