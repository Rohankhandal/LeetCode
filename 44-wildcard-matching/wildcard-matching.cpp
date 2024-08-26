class Solution {
public:
    bool solve(int i,int j,string str,string pattern)
    {
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;
        if(i<0 && j>=0)
        {
            //check whether remainig string in pattern is all * or not
            for(int m=0;m<=j;m++)
            {
                if(pattern[m]!='*') return false;
            }
            return true;
        }


        //match
        if(str[i]==pattern[j] || pattern[j]=='?')
        {
            return solve(i-1,j-1,str,pattern);
        }
        if(pattern[j]=='*')
        {
            return solve(i-1,j,str,pattern) || solve(i,j-1,str,pattern);
        }
         
        return false;
    }

     bool solveMem(int i,int j,string &str,string &pattern,vector<vector<int>>&dp)
    {
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;
        if(i<0 && j>=0)
        {
            //check whether remainig string in pattern is all * or not
            for(int m=0;m<=j;m++)
            {
                if(pattern[m]!='*') return false;
            }
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];


        //match
        if(str[i]==pattern[j] || pattern[j]=='?')
        {
            return  dp[i][j]=solveMem(i-1,j-1,str,pattern,dp);
        }
        if(pattern[j]=='*')
        {
            return  dp[i][j]=(solveMem(i-1,j,str,pattern,dp) || solveMem(i,j-1,str,pattern,dp));
        }
         
        return  dp[i][j]=false;
    }


    //change into 1-based index Memoziaition
    bool solveMem1Index(int i,int j,string &str,string &pattern,vector<vector<int>>&dp)
    {
        if(i==0 && j==0) return true;
        if(i>0 && j==0) return false;
        if(i==0 && j>0)
        {
            //check whether remainig string in pattern is all * or not
            for(int m=1;m<=j;m++)
            {
                if(pattern[m-1]!='*') return false;
            }
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];


        //match
        if(str[i-1]==pattern[j-1] || pattern[j-1]=='?')
        {
            return  dp[i][j]=solveMem1Index(i-1,j-1,str,pattern,dp);
        }
        if(pattern[j-1]=='*')
        {
            return  dp[i][j]=(solveMem1Index(i-1,j,str,pattern,dp) || solveMem1Index(i,j-1,str,pattern,dp));
        }
         
        return  dp[i][j]=false;
    }


    //3.Tabluation
    bool solveTab(string &str,string &pattern)
    {
        int n1=str.size();
        int n2=pattern.size();
        vector<vector<bool>>dp(n1+1,vector<bool>(n2+1,false));

        dp[0][0]=true;

        for(int j=1;j<=n2;j++)
        {
            bool flag=true;
           //check whether remainig string in pattern is all * or not
            for(int m=1;m<=j;m++)
            {
                if(pattern[m-1]!='*')
                {
                    flag=false;
                    break;
                } 
            }
            dp[0][j]=flag;
        }

        
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                //match
                if(str[i-1]==pattern[j-1] || pattern[j-1]=='?')
                {
                     dp[i][j]=dp[i-1][j-1];
                }
                else if(pattern[j-1]=='*')
                {
                     dp[i][j]=(dp[i-1][j] || dp[i][j-1]);
                }
                else dp[i][j]=false;
            }
        }

        return dp[n1][n2];
        
    }
    bool isMatch(string str, string pattern) {
        int n1=str.size();
        int n2=pattern.size();

        //1.Recursion
        // return solve(n1-1,n2-1,str,pattern);

        //2.Memoziation
        // vector<vector<int>>dp(n1,vector<int>(n2,-1));
        // return solveMem(n1-1,n2-1,str,pattern,dp);

        //Change into 1-index memoziation for Tablaution
        // vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        // return solveMem1Index(n1,n2,str,pattern,dp);


        //3.Tabluation
        return solveTab(str,pattern);
    }
};