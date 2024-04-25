class Solution {
public:
    int solve(int i,string s,char last,int k)
    {
        if(i>=s.size()) return 0;

        int ans1=0;
        if(last=='{' || abs(s[i]-last)<=k)
        {
            ans1=1+solve(i+1,s,s[i],k);  //include
        }
        //exclude
        int ans2=0+solve(i+1,s,last,k);
        return max(ans1,ans2);
    }

//     Time complexity: O(n∗27)
//      Space complexity:O(n∗27) to O(26)
    int solveMem(int i,string &s,int last,int k,vector<vector<int>>&dp)
    {
        if(i>=s.size()) return 0;
        if(dp[i][last]!=-1) return dp[i][last];

        int ans1=0;
        char ch=last+'a';  //IMP 
        if(last==26 || abs(s[i]-ch)<=k)
        {
            ans1=1+solveMem(i+1,s,s[i]-'a',k,dp);  //include
        }
        //exclude
        int ans2=0+solveMem(i+1,s,last,k,dp);
        return dp[i][last]=max(ans1,ans2);
    }


    //3.Tabluation:-
    int solveTab(string &s,int k)
    {
         vector<vector<int>>dp(s.size()+2,vector<int>(27,0));
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            for(int last=26;last>=0;last--)
            {
                int ans1=0;
                char ch=last+'a';  //IMP 
                if(last==26 || abs(s[i]-ch)<=k)
                {
                    ans1=1+dp[i+1][s[i]-'a'];  //include
                }
                //exclude
                int ans2=0+dp[i+1][last];
                dp[i][last]=max(ans1,ans2);
            }
        }
        return dp[0][26];   //IMP
    }

    //4.Space:-
    int space(string &s,int k)
    {
        //  vector<vector<int>>dp(s.size()+2,vector<int>(27,0));
         vector<int>curr(27,0),next(27,0);
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            for(int last=26;last>=0;last--)
            {
                int ans1=0;
                char ch=last+'a';  //IMP 
                if(last==26 || abs(s[i]-ch)<=k)
                {
                    ans1=1+next[s[i]-'a'];  //include
                }
                //exclude
                int ans2=0+next[last];

                curr[last]=max(ans1,ans2);
            }
            next=curr;
        }
        return next[26];   //IMP
    }
    int longestIdealString(string s, int k) {
         //char last='{';  //suppose any character
        //    return solve(0,s,last,k);

        //2.Memoziation
        // vector<vector<int>>dp(s.size()+2,vector<int>(27,-1));
        // return solveMem(0,s,26,k,dp);

        //3/Tabluation
        // return solveTab(s,k);

        //4.Space Optimize
        return space(s,k);
    }
};