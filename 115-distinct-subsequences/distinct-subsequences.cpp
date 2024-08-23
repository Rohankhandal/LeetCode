class Solution {
public:
    int solve(string s,string t,int i,int j)
    {
        if(j>=t.size())
        {
            return 1;
        }
        if(i>=s.size())
        {
            return 0;
        }

        int match=0;
        if(s[i]==t[j])
        {
            match=solve(s,t,i+1,j+1);
        }
       
        int noMatch=solve(s,t,i+1,j);

        return match+noMatch;
       
    }

    //2.Memoziation
    int solveMem(string s,string t,int i,int j,vector<vector<int>>&dp)
    {
        if(j>=t.size())
        {
            return 1;
        }
        if(i>=s.size())
        {
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int match=0;
        if(s[i]==t[j])
        {
            match=solveMem(s,t,i+1,j+1,dp);
        }
       
        int noMatch=solveMem(s,t,i+1,j,dp);

        return dp[i][j]=(match+noMatch);
       
    }
    int numDistinct(string s, string t) {
        if(s.size()<t.size()) return 0;

        //1.Recursion
        // return solve(s,t,0,0);

        //2.Memoziation
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return solveMem(s,t,0,0,dp);
    }
};