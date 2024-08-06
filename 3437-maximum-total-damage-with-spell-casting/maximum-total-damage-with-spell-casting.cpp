class Solution {
public:

    long long solve(vector<int>& uniqueEle, int i,vector<long long>&dp,map<int,int>&mp) {
        int n = uniqueEle.size();
        if (i >= n) return 0;
        

        if(dp[i]!=-1) return dp[i];
        long long take = 0;
        int nextIdx = i + 1;

        
        // Move to the next distinct element and handle conditions
        while (nextIdx < n && (uniqueEle[nextIdx] == uniqueEle[i] + 2 || uniqueEle[nextIdx] == uniqueEle[i] + 1)) nextIdx++;

        take += 1ll*uniqueEle[i]*mp[uniqueEle[i]] + solve(uniqueEle, nextIdx,dp,mp);

        long long noTake = solve(uniqueEle, i + 1,dp,mp);

       dp[i]= max(take, noTake);
        return dp[i];
    }

    long long maximumTotalDamage(vector<int>& power) {
       
        // sort(power.rbegin(),power.rend());
        map<int,int>mp;
        for(auto &it:power)
        {
            mp[it]++;
        }
        vector<int>uniqueEle;
        for(auto&it:mp) //sort also
        {
            uniqueEle.push_back(it.first);
        }

        int n=uniqueEle.size();
        vector<long long >dp(n+1,-1);
        return solve(uniqueEle,0,dp,mp);
        // return 0;
    }
};