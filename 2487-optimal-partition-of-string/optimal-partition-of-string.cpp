class Solution {
public:
    int partitionString(string s) {
        vector<int> hash(26,0);
        int count=0,i;
        for(i=0;i<s.size();i++)
        {
            if(hash[s[i]-'a']==1)
            {
                count++;
                for(int j=0;j<26;j++)
                {
                    hash[j]=0;
                }
                hash[s[i]-'a']=1;
            }
            else
            {
                hash[s[i]-'a']++;
            }
        }
        if(i==s.size())
        {
            count++;
        }
        return count;
    }
};