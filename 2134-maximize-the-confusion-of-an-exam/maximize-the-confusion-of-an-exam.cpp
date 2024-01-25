class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l=0,r=0,ans=0;
        int maxFreq=0;
        int n=answerKey.size();
        vector<int>hash(26,0);
        while(r<n)
        {
            hash[answerKey[r]-'A']++;
            maxFreq=max(maxFreq,hash[answerKey[r]-'A']);
            if(r-l+1-maxFreq>k)
            {
                hash[answerKey[l]-'A']--;
                l++;
                maxFreq=*max_element(hash.begin(),hash.end());
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};