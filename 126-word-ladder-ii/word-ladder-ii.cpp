class Solution {
public:
    unordered_map<string,int>mpp;  //map to store minimum steps
    vector<vector<string>>ans;
    string b;
    void dfs(string word,vector<string>&seq)
    {
        if(word==b) {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());  //backtrack
            return ;
        }

        int steps=mpp[word];
        int sz=word.size();

        for(int i=0;i<sz;i++)
        {
            char original=word[i];
            for(char ch='a';ch<='z'; ch++)
            {
                word[i]=ch;
                if(mpp.find(word)!=mpp.end() && mpp[word]+1==steps)
                {
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i]=original;
        }

    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        //step:1 => get the minimum step to reach endWord (Using code of Word Ladder 1)
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<string>q;
        b=beginWord;
        q.push({beginWord});
        mpp[beginWord]=1;
        st.erase(beginWord);
        int size=beginWord.size();

        while(!q.empty())
        {
            string word=q.front();
            int steps=mpp[word];
            q.pop();

            if(word==endWord) break;

            for(int i=0;i<size;i++)
            {
                char original=word[i];
                for(char ch='a' ; ch<='z' ; ch++)
                {
                    word[i]=ch;
                    if(st.count(word))
                    {
                        q.push(word);
                        st.erase(word);
                        mpp[word]=steps+1;
                    }
                }
                word[i]=original;
            }
        }

        //step:2 => backtrack in map  from end to begin  to get the answer
        if(mpp.find(endWord)!=mpp.end())
        {
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};


// Breadth-First Search (BFS):

// Pushing the beginWord into the queue takes O(1) time.
// The main loop of the BFS runs until the queue is empty, and each iteration involves:

// Popping an element from the queue, which takes O(1) time.
// Iterating through each character of the current word, which takes O(M) time.
// For each character, trying all possible transformations (26 letters), which takes O(M) time.
// Checking if the transformed word exists in the set and adding it to the queue, which takes O(1) time on average (due to the hash table-based implementation of unordered_set).


// The total time complexity for the BFS part is O(M^2 * N), as there are at most N words in the queue, and each iteration takes O(M) time.


// Depth-First Search (DFS):

// The DFS function is called once for each valid path found in the BFS step.
// The DFS function iterates through each character of the current word, which takes O(M) time.
// For each character, it tries all possible transformations (26 letters), which takes O(M) time.
// Checking if the transformed word is part of the shortest path (by looking it up in the mpp map) takes O(1) time on average.
// Pushing and popping the word from the seq vector takes O(1) time.
// The total time complexity for the DFS part is O(M^2 * k), where k is the number of valid paths found, as the DFS function is called once for each valid path.



// Overall, the time complexity of the findLadders function is O(M^2 * N), as the BFS step dominates the time complexity.
// The space complexity is O(M * N), as we use an unordered_set to store the word list, a queue for the BFS, and a mpp map to store the minimum steps required to reach each word. The ans vector can potentially store up to N valid paths, each of which can have up to M words.