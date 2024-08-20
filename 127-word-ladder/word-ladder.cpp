class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        //for marked
        st.erase(beginWord);

        while(!q.empty())
        {
            string word=q.front().first;
            int step=q.front().second;
            q.pop();
            if(endWord==word) return step;
            int len=word.size();
            for(int i=0;i<len;i++)
            {
                char original=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }

                word[i]=original;
            }
        }

        return 0;
    }
};