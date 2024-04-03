class Solution {
public:
    int solve(string a,string b,int i,int j)
    {
        if(i==a.size())  return b.size()-j;
        if(j==b.size())  return a.size()-i;

        int ans=0;
        if(a[i]==b[j]){
            ans=0+solve(a,b,i+1,j+1);
        }
        else 
        {
            int insert=1+solve(a,b,i,j+1);
            int deleted=1+solve(a,b,i+1,j);
            int replace=1+solve(a,b,i+1,j+1);

            ans=min(insert,min(deleted,replace));
        }
        return ans;

    }
    int solveTop(string a,string b,int i,int j,vector<vector<int>>&dp)
    {
        if(i==a.size())  return b.size()-j;
        if(j==b.size())  return a.size()-i;
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int ans=0;
        if(a[i]==b[j]){
            ans=0+solveTop(a,b,i+1,j+1,dp);
        }
        else 
        {
            int insert=1+solveTop(a,b,i,j+1,dp);
            int deleted=1+solveTop(a,b,i+1,j,dp);
            int replace=1+solveTop(a,b,i+1,j+1,dp);

            ans=min(insert,min(deleted,replace));
        }
        dp[i][j]=ans;
        return dp[i][j];

    }
    int minDistance(string a, string b) {
    //    return  solve(a,b,0,0);

        vector<vector<int>>dp(a.size(),vector<int>(b.size(),-1));
        return solveTop(a,b,0,0,dp);
    }
};