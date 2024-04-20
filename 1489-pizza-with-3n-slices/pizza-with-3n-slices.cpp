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
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        //1.Recursion
        //  int option1=solve(1,n/3,slices);  //include last one and exclude first one

        //  slices[n-1]=0;
        //  int option2=solve(0,n/3,slices);  //start from starting and not include last one

        //  return max(option1,option2);


        //2.Memoziation
        vector<vector<int>>dp1(n+1,vector<int>(n+1,-1));
        int option1=solveMem(1,n/3,slices,dp1);  //include last one and exclude first one
 
    //IMP => now we have to initialize dp with -1 becauase through above line dp have values
        vector<vector<int>>dp2(n+1,vector<int>(n+1,-1));
        slices[n-1]=0;
        int option2=solveMem(0,n/3,slices,dp2);  //start from starting and not include last one

        return max(option1,option2);
    }
};