class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(auto &word:words)
        {
            int i=0;
             unordered_map<char,char>forward;
            unordered_map<char,char>reverse;
            for(i=0;i<word.size();i++)
            {
                if(forward.find(pattern[i])!=forward.end() && forward[pattern[i]]!=word[i])
                {
                    break;
                }
                if(reverse.find(word[i])!=reverse.end() && reverse[word[i]]!=pattern[i])
                {
                    break;
                }
                forward[pattern[i]]=word[i];
                reverse[word[i]]=pattern[i];

            } 
            if(i==word.size()) ans.push_back(word);
        }
        return ans;

               
    }
};