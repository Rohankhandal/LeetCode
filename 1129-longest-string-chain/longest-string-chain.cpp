class Solution {
public:
    bool isSequence(string&prev,string&curr)
    {
        int n=prev.size();
        int m=curr.size();
        if(n+1!=m) return false;
        int i=0,j=0;
        int cnt=0;
        while(i<n && j<m)
        {

            if(prev[i]!=curr[j])
            {
                cnt++;j++;continue;
            }
            if(cnt>=2) return false; 
 

            i++;
            j++;
        }
       if(i==n && j==m) return true;
       return (cnt==0);
    }
    int longestStrChain(vector<string>& words) {
        auto comp=[&](string &a,string &b)
        {
            if(a.size()==b.size())
            {
                return a<b;
            }
            return a.size()<b.size();
        };
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            cout<<words[i]<<endl;
           
        }
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(isSequence(words[j],words[i]) && 1+dp[j]>dp[i])
                {
                    dp[i]=1+dp[j];
                    maxi=max(maxi,dp[i]);
                }
            }
        }
      
        return maxi;
    }
};