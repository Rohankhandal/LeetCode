class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxfreq(26, 0);
        for (const string& word : words2) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                maxfreq[i] = max(maxfreq[i], freq[i]);
            }
        }

        vector<string> ans;
        for (const string& word : words1) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            bool isValid = true;
            for (int i = 0; i < 26; ++i) {
                if (freq[i] < maxfreq[i]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) ans.push_back(word);
        }

        return ans;
    }
};
