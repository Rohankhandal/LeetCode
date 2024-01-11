class Solution {
public:
    int minSteps(string s, string t) {
        int hash1[26]={0};
        int hash2[26]={0};
        for(int i=0;i<s.size();i++)
        {
            hash1[s[i]-97]++;
        }
        for(int i=0;i<26;i++)
        {
            cout<<hash1[i]<<" ";
        }
        //decrease
        for(int i=0;i<t.size();i++)
        {
            hash2[t[i]-97]++;
        }
        cout<<endl;
        for(int i=0;i<26;i++)
        {
            cout<<hash2[i]<<" ";
        }
        int sum=0;
        for(int i=0;i<26;i++)
        {
            int temp=hash1[i]-hash2[i];
            if(temp>0)
            {
                sum+=temp;
            }
        }
        return sum;
    }
};