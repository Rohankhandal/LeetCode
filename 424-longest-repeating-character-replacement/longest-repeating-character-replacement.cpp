class Solution {
public:
    int characterReplacement(string s, int k) {
        int start=0,end=0,res=0;
        int maxFreq=0;
        vector<int>hash(26,0);
        while(end<s.size())
        {
            hash[s[end]-'A']++;  //count the frequency
            maxFreq=max(maxFreq,hash[s[end]-'A']);  //compare with maxFreq
            if(end-start+1-maxFreq>k)   //check whether window is valid after replacement of k char (or imagine after removing ) window is valid or not
            {
                hash[s[start]-'A']--;  //if not valid then increment start pointer
                start++;
                maxFreq=*max_element(hash.begin(),hash.end());
            }
            res=max(res,end-start+1);   //find largest window
            end++;
        }
        return res;
    }
};