class Solution {
public:
    int maxScore(string s) {
        int zero=0;int one=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            
            if(s[i]=='1') one++;
        }
        int ans=INT_MIN;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='0')
            {
                zero++;
            }
            if(s[i]=='1')
            {
                one--;
            }
            ans=max(zero+one,ans);
        }
        return ans;
    }
};