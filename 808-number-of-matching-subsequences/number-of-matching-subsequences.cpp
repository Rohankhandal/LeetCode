// class Solution {
// public:
//     int numMatchingSubseq(string s, vector<string>& words) {
//         int count = 0;
//         for (int i = 0; i < words.size(); ++i)
//         {
//             int start = 0,flag= 1, k;
//             for (int j = 0; j < words[i].size(); ++j)
//             {
//                 k= s.find(words[i][j],start);
//                 if (k == -1) 
//                 {
//                     flag = 0;
//                     break;
//                 }
//                 start = k+1;
//             }
//             count += flag;
//         }
//         return count;
//     }
// };


class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // Map to store the positions of each character in 's'
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);
        }

        int count = 0;

        // Check each word in 'words'
        for (const auto& word : words) {
            int lastIndex = -1;
            bool isSubsequence = true;

            // Check if the word is a subsequence of 's'
            for (char c : word) {
                if (mp.find(c) == mp.end()) {
                    isSubsequence = false;
                    break;
                }

                // Find the next occurrence of 'c' after 'lastIndex'
                auto it = upper_bound(mp[c].begin(), mp[c].end(), lastIndex);
                if (it == mp[c].end()) {
                    isSubsequence = false;
                    break;
                }
                lastIndex = *it;
            }

            if (isSubsequence) {
                count++;
            }
        }

        return count;
    }
};
