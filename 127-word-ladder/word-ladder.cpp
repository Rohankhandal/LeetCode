// T.c: O(N * word.length * 26 * logN)

class Solution {
public:
    // Function to find the shortest transformation sequence from beginWord to endWord
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Initialize a set with all words from the wordList for quick lookup
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Queue to perform BFS; stores pairs of the current word and the transformation step count
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        // Mark the beginWord as visited by erasing it from the set
        st.erase(beginWord);

        // BFS loop to explore all possible transformations
        while (!q.empty()) {  
            string word = q.front().first;
            int step = q.front().second;
            q.pop();

            // If the current word is the endWord, return the step count
            if (endWord == word) return step;

            int len = word.size();
            for (int i = 0; i < len; i++) {
                char original = word[i];  // Store the original character

                // Try all possible single character transformations
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    // If the transformed word is in the set, it is a valid transformation
                    if (st.find(word) != st.end()) {
                        // Mark the word as visited and push it to the queue with incremented step count
                        st.erase(word);
                        q.push({word, step + 1});
                    }
                }

                // Restore the original character after exploring all transformations for the position
                word[i] = original;
            }
        }

        // If no transformation sequence is found, return 0
        return 0;
    }
};
