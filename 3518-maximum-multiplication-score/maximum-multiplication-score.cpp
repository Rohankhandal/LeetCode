class Solution {
public:
    long long solve(vector<int>& a, vector<int>& b,int i,int j,vector<vector< long long>>&dp)
    {
        int n=a.size();
        int m=b.size();

        if(i>=n) return 0;

        if(j>=m) return INT_MIN;

        if(dp[i][j]!=-1) return dp[i][j];

        //take j index
        long long take=a[i]*1LL*b[j]+solve(a,b,i+1,j+1,dp);

        long long skip=0+solve(a,b,i,j+1,dp);

        return dp[i][j]=max(take,skip);
    }
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int m=b.size();
        vector<vector< long long>>dp(n,vector< long long>(m,-1));
        return solve(a,b,0,0,dp);
    }
};