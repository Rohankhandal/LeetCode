class Solution {
public:
bool matches(string word,string pattern)
{
    vector<int>wordToPattern(26,0);  //we need to map for check in both direction mapping 
    // e.g word="abb" pattern="ccc"  //we can't use two map , then result is mapping is correct 
    //which is wrong
    vector<int>patternToWord(26,0);

    for(int index=0;index<word.size();index++)
    {
        char wordChar=word[index];
        char patternChar=pattern[index];

        if(patternToWord[patternChar-'a']==0)
        {
            patternToWord[patternChar-'a']=wordChar;
        }
        if(wordToPattern[wordChar-'a']==0)
        {
            wordToPattern[wordChar-'a']=patternChar;
        }

        //check for mapping e.g word="abb" pattern="ccc"
        if(patternToWord[patternChar-'a']!=wordChar || wordToPattern[wordChar-'a']!=patternChar)
        {
            return false;
        }
    }
    return true;


}
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(auto &str:words)
        {
            if(matches(str,pattern))
            {
                ans.push_back(str);
            }
        }
        return ans;
    }
};