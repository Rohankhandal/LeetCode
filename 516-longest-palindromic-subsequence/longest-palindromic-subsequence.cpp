class Solution {
public:
    int solve(string t1,string t2,int i,int j)
    {
       if(i==t1.size()) return 0;
       if(j==t2.size()) return 0;
        int ans=0;
        if(t1[i]==t2[j])
        {
            ans+=1+solve(t1,t2,i+1,j+1);
        }
        else
        {
            ans+=0+max(solve(t1,t2,i,j+1),solve(t1,t2,i+1,j));
        }
        return ans;
    }
    int solveTop(string &t1,string &t2,int i,int j ,vector<vector<int>>&dp)
    {
       if(i==t1.size()) return 0;
       if(j==t2.size()) return 0;
       if(dp[i][j]!=-1) return dp[i][j];

        int ans=0;
        if(t1[i]==t2[j])
        {
            ans+=1+solveTop(t1,t2,i+1,j+1,dp);
        }
        else
        {
            ans+=0+max(solveTop(t1,t2,i,j+1,dp),solveTop(t1,t2,i+1,j,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int solveTab(string &a,string &b)
    {
         int len1=a.length();
        int len2=b.length();
       vector<vector<int>>dp(len1+1,vector<int>(len2+1,0));

        int ans=0;
       
        for(int i=len1-1;i>=0;i--)
        {
            for(int j=len2-1;j>=0;j--)
            {
                int ans=0;
                if(a[i]==b[j])
                {
                    ans+=1+dp[i+1][j+1];
                }
                else
                {
                    ans+=0+max(dp[i][j+1],dp[i+1][j]);
                }
                dp[i][j]=ans;
                
            }
        }
        return dp[0][0];

       
    }
    int longestPalindromeSubseq(string s) {
        string a=s;
        reverse(s.begin(),s.end());
        string b=s;

        // return solve(a,b,0,0);

        vector<vector<int>>dp(a.length(),vector<int>(b.length(),-1));
        return solveTop(a,b,0,0,dp);


        // return solveTab(a,b);
    }
};