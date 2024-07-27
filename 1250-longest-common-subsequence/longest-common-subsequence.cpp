class Solution {
public:
    int solve(string text1, string text2,int i,int j)
    {
        if(i>=text1.size() || j>=text2.size()) return 0;

        int op1=INT_MIN,op2=INT_MIN,op3=INT_MIN;
        if(text1[i]==text2[j])
        {
            op1=1+solve(text1,text2,i+1,j+1);
        }
        else
        {
            op2=solve(text1,text2,i+1,j);
            op3=solve(text1,text2,i,j+1);
            
        }
        return max({op1,op2,op3});
    }

    // 2.Memoziation
    int solveMem(string &text1, string &text2,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=text1.size() || j>=text2.size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int op1=INT_MIN,op2=INT_MIN,op3=INT_MIN;
        if(text1[i]==text2[j])
        {
            op1=1+solveMem(text1,text2,i+1,j+1,dp);
        }
        else
        {
            op2=solveMem(text1,text2,i+1,j,dp);
            op3=solveMem(text1,text2,i,j+1,dp);
            
        }
        return dp[i][j]=max({op1,op2,op3});
    }
    int longestCommonSubsequence(string text1, string text2) {
        // return  solve(text1,text2,0,0);


        // 2.Memoziation
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solveMem(text1,text2,0,0,dp);
    }
};