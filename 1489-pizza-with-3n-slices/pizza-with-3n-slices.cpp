class Solution {
public:
    int solve(int i,int n,vector<int>&slices)
    {
        if(n==0 || i>=slices.size()) return 0;

        int include=slices[i]+solve(i+2,n-1,slices);
        int exclude=0+solve(i+1,n,slices);

        return max(include,exclude);
    }
    //2.Memoization
    int solveMem(int i,int n,vector<int>&slices,vector<vector<int>>&dp)
    {
        if(n==0 || i>=slices.size()) return 0;
        if(dp[i][n]!=-1) return dp[i][n];

        int include=slices[i]+solveMem(i+2,n-1,slices,dp);
        int exclude=0+solveMem(i+1,n,slices,dp);

        return dp[i][n]=max(include,exclude);
    }

    //3.Tabluation
    int solveTab(vector<int>&slices)
    {
        int n=slices.size();
        vector<vector<int>>dp1(n+2,vector<int>(n+2,0));
        vector<vector<int>>dp2(n+2,vector<int>(n+2,0));

        for(int i=n-1;i>=1;i--)
        {
            for(int tar=1;tar<=n/3;tar++)
            {
                int include=slices[i]+dp1[i+2][tar-1];
                int exclude=0+dp1[i+1][tar];

                dp1[i][tar]=max(include,exclude);
            }
        }

        //take starting element
        for(int i=n-2;i>=0;i--)
        {
            for(int tar=1;tar<=n/3;tar++)
            {
                int include=slices[i]+dp2[i+2][tar-1];
                int exclude=0+dp2[i+1][tar];

                dp2[i][tar]=max(include,exclude);
            }
        }

        return max(dp1[1][n/3],dp2[0][n/3]);    //IN DP1 answer store at dp1[1][n/3];        
    }


    //4. Space
    int space(vector<int>&slices)
    {
        int n=slices.size();
        vector<int>curr(n+1,0);
        vector<int>next1(n+1,0);
        vector<int>next2(n+1,0);

        for(int i=n-1;i>=1;i--)
        {
            for(int tar=1;tar<=n/3;tar++)
            {
                int include=slices[i]+next2[tar-1];
                int exclude=0+next1[tar];

                curr[tar]=max(include,exclude);
            }
            next2=next1;
            next1=curr;
        }
        int ans1=next1[n/3];

        // Reset vectors to zero
        curr.assign(n + 1, 0);
        next1.assign(n + 1, 0);
        next2.assign(n + 1, 0);
        //take starting element
        for(int i=n-2;i>=0;i--)
        {
            for(int tar=1;tar<=n/3;tar++)
            {
                int include=slices[i]+next2[tar-1];
                int exclude=0+next1[tar];

                curr[tar]=max(include,exclude);
            }
            next2=next1;
            next1=curr;
        }
        int ans2=next1[n/3];
        return max(ans1,ans2);        
    }


    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        //1.Recursion
        //  int option1=solve(1,n/3,slices);  //include last one and exclude first one

        //  slices[n-1]=0;
        //  int option2=solve(0,n/3,slices);  //start from starting and not include last one

        //  return max(option1,option2);


        //2.Memoziation
        // vector<vector<int>>dp1(n+1,vector<int>(n+1,-1));
        // int option1=solveMem(1,n/3,slices,dp1);  //include last one and exclude first one
 
        // //IMP => now we have to initialize dp with -1 becauase through above line dp have values
        // vector<vector<int>>dp2(n+1,vector<int>(n+1,-1));
        // slices[n-1]=0;
        // int option2=solveMem(0,n/3,slices,dp2);  //start from starting and not include last one

        // return max(option1,option2);


        //3.Tabluation
        
        // return solveTab(slices);


        //4.SPace
        return space(slices);

    }
};