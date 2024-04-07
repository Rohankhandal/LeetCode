class Solution {
public:
    int solve(int idx,int open,string &s,int n,vector<vector<int>>&dp)
    {
        if(idx==n)
        {
            if(open==0) return true;
            return false;
        }
        if(dp[idx][open]!=-1)
        {
            return dp[idx][open]==1?true:false;
        }
        bool isValid=false;
        if(s[idx]=='(')
        {
            isValid|=solve(idx+1,open+1,s,n,dp);
        }
        else if(s[idx]=='*')
        {
            isValid|=solve(idx+1,open+1,s,n,dp); //suppose *='('
            isValid|=solve(idx+1,open,s,n,dp);  //suppose *=""
            if(open>0)
            isValid|=solve(idx+1,open-1,s,n,dp);  //suppose *=")"
        }
        else if(open>0)
        {
            isValid|=solve(idx+1,open-1,s,n,dp);
        }


        return dp[idx][open]=isValid;
    }
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return  solve(0,0,s,n,dp);
    }
};