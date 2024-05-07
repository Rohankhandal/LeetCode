class Solution {
public:
    bool check(string s,int k)
    {
        int n=s.size();
        char cnt1[26]={0};
        for(int i=0;i<k;i++)
        {
            cnt1[s[i]-'a']++;
        }
       
        for(int i=k;i<n;i+=k)
        {
            char cnt2[26]={0};
            for(int j=i;j<k+i;j++)
            {
                cnt2[s[j]-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                if(cnt1[i]!=cnt2[i]) return false;
            }

        }
        return true;
    }
    int minAnagramLength(string s) {
        int n=s.size();
        for(int i=1;i<=n;i++)
        {
            if(n%i==0 && check(s,i))
            {
                return i;
            }
        }
        return -1;
    }
};