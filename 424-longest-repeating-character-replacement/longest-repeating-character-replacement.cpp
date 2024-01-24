class Solution {
public:
    int characterReplacement(string s, int k) {
        int start=0,end=0,res=0;
        int maxFreq=0;
        vector<int>hash(26,0);
        while(end<s.size())
        {
            hash[s[end]-'A']++;
            maxFreq=max(maxFreq,hash[s[end]-'A']);
            if(end-start+1-maxFreq>k)
            {
                hash[s[start]-'A']--;
                start++;
                maxFreq=*max_element(hash.begin(),hash.end());
            }
            res=max(res,end-start+1);
            end++;
        }
        return res;
    }
};