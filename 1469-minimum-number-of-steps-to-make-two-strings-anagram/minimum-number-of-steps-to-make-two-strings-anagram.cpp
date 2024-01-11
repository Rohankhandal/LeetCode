class Solution {
public:
    int minSteps(string s, string t) {
        int hash1[26]={0};
        
        for(int i=0;i<s.size();i++)
        {
            hash1[s[i]-97]++;
            hash1[t[i]-'a']--;
        }
        
        int sum=0;
        for(auto i: hash1)
        {
            
            if(i>0)
            {
                sum+=i;
            }
        }
        return sum;
    }
};