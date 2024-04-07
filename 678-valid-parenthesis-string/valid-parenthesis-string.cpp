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
    int solveTab(string &s,int n)
    {
        vector<vector<bool>>dp(n+2,vector<bool>(n+2,false));
        
        // for(int i=0;i<=n;i++)
        // {
        //     dp[i][0]=true;
        // }
        dp[n][0]=true;
                
        for(int idx=n-1;idx>=0;idx--)
        {
            for(int open=n;open>=0;open--)
            {
                bool isValid=false;

                if(s[idx]=='(')
                {
                    isValid|=dp[idx+1][open+1];
                }
                else if(s[idx]=='*')
                {
                    isValid|=dp[idx+1][open+1]; //suppose *='('
                    isValid|=dp[idx+1][open];  //suppose *=""
                    if(open>0)                                                                //IMP to Check
                    isValid|=dp[idx+1][open-1];  //suppose *=")"
                }
                else
                {
                    if(open>0)
                    isValid|=dp[idx+1][open-1];
                }

                dp[idx][open]=isValid;
            }
            
        }
        return dp[0][0];
    }
    bool checkValidString(string s) {
        int n=s.size();
       
       return  solveTab(s,n);
    }
};