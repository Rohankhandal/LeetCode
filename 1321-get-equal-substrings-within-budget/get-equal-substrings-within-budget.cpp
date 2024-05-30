class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxLen=0;
        int i=0,j=0;
        int n=s.size();
        int cost=0;
        while(j<n){
            cost=cost+abs(s[j]-t[j]);

            if(cost>maxCost)
            {
                while(i<=j && cost>maxCost)
                {
                    cost-=abs(s[i]-t[i]);
                    i++;
                }
            }
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        return maxLen;
    }
};