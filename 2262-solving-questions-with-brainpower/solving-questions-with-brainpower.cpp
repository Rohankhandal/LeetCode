class Solution {
public:
    long long f(vector<vector<int>>&ques,int i, vector<long long>&dp)
    {
        if(i>=ques.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        
        long long  take=ques[i][0]+f(ques,i+ques[i][1]+1,dp);
        long long  skip=0+f(ques,i+1,dp);

        return dp[i]=max(take,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int i=0;
        int n=questions.size();
        vector<long long >dp(n,-1);
        return f(questions,i,dp);
    }
};