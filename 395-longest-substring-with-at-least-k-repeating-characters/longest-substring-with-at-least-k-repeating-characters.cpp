class Solution {
public:
bool atLeastK(int freq[],int k)
{
    for(int i=0;i<26;i++)
    {
        if(freq[i]!=0&&freq[i]<k)
        {
            return false;
        }
    }
    return true;
}
void setZero(int freq[])
{
    for(int i=0;i<26;i++)
    {
        freq[i]=0;
    }
}
    int longestSubstring(string s, int k) {
        int freq[26];
        int maxi=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            setZero(freq);
            for(int j=i;j<n;j++)
            {
                freq[s[j]-'a']++;
                if(atLeastK(freq,k))
                {
                    maxi=max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};