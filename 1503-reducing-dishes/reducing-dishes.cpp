class Solution {
public:
    int solve(vector<int>&sat,int time,int i)
    {
        if(i>=sat.size()) return 0;
        
        int include=sat[i]*time+solve(sat,time+1,i+1);

        int exclude=0+solve(sat,time,i+1);

        return max({include,exclude,0});

    }
    int solveMem(vector<int>&sat,int time,int i,vector<vector<int>>&dp)
    {
        if(i>=sat.size()) return 0;
        if(dp[i][time]!=-1) return dp[i][time];
        
        int include=sat[i]*time+solveMem(sat,time+1,i+1,dp);

        int exclude=0+solveMem(sat,time,i+1,dp);

        return dp[i][time]=max({include,exclude,0});

    }


    int solveTab(vector<int>&sat)
    {
        int n=sat.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
       
        for(int i=n-1;i>=0;i--)
        {
            for(int time=i;time>=0;time--)
            {
                int include=sat[i]*time+dp[i+1][time+1];

                int exclude=0+dp[i+1][time];

                dp[i][time]=max({include,exclude,0});
            }
        }
        return dp[0][0];
        

    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int time=1;
        int n=satisfaction.size();

        // return solve(satisfaction,time,0);

        //2.Memoriztion
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveMem(satisfaction,time,0,dp);

        //3.Tabluation
        return solveTab(satisfaction);
    }
};