class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len1=s.size();
        int n=t.size();
        int j=0;
        if(len1==0) return true;
        for(int i=0;i<n;i++)
        {
            if(t[i]==s[j])
            {
                j++;
                if(j==len1) return true;
            }

        }
        return false;
    }
};