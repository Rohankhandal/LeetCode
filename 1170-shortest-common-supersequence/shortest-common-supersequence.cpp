class Solution {
public:
    string solveTab(string &text1, string &text2)
    {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int op1=INT_MIN,op2=INT_MIN,op3=INT_MIN;
                if(text1[i]==text2[j])
                {
                    op1=1+dp[i+1][j+1];
                }
                else
                {
                    op2=dp[i+1][j];
                    op3=dp[i][j+1];
                    
                }
                dp[i][j]=max({op1,op2,op3});
            }
        }

        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        string ans="";
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(text1[i]==text2[j])
            {
                //common character
                ans+=text1[i];
                i++;
                j++; //go to next diagonal 
            }
            else if(dp[i+1][j]>dp[i][j+1])
            {
                ans+=text1[i];
                i++;
            }
            else
            {
                ans+=text2[j];
                j++;
            }
        }

        //edge case
        while(i<n)  //some remaining characters in string text1
        {
            ans+=text1[i];
            i++;
        }

        while(j<m)  //some remaining characters in string text2
        {
            ans+=text2[j];
            j++;
        }

        return ans;
        
        
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();

         return solveTab(str1,str2);
         
    }
};