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
    int longestIdealString(string s, int k) {
         //char last='{';  //suppose any character
        //    return solve(0,s,last,k);

        //2.Memoziation
        vector<vector<int>>dp(s.size()+2,vector<int>(27,-1));
        return solveMem(0,s,26,k,dp);
    }
};