class Solution {
public:
    int solve(vector<int>&days,vector<int>&costs,int i)
    {
        if(i>=days.size())
        {
            return 0;
        }
        int option1=costs[0]+solve(days,costs,i+1);

        int index=i;
        int j;
        for(j=i;j<days.size()&&days[j]<days[index]+7;j++);
        int option2=costs[1]+solve(days,costs,j);

        index=i;
        for(j=i;j<days.size()&&days[j]<days[index]+30;j++);
        int option3=costs[2]+solve(days,costs,j);

        return min({option1,option2,option3});

    }


    //Memoization
    int solveMem(vector<int>&days,vector<int>&costs,int i,vector<int>&dp)
    {
        if(i>=days.size())
        {
            return 0;
        }
        if(dp[i]!=-1) return dp[i];

        //1-Day cost
        int option1=costs[0]+solveMem(days,costs,i+1,dp);

        //2-Day cost
        int index=i;
        int j;
        for(j=i;j<days.size()&&days[j]<days[index]+7;j++);
        int option2=costs[1]+solveMem(days,costs,j,dp);


        //3-Day cost
        index=i;
        for(j=i;j<days.size()&&days[j]<days[index]+30;j++);
        int option3=costs[2]+solveMem(days,costs,j,dp);

        return dp[i]=min({option1,option2,option3});

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // return solve(days,costs,0);

        // 2.Memoization
        int n=days.size();
        vector<int>dp(n+1,-1);
        return solveMem(days,costs,0,dp);
    }
};