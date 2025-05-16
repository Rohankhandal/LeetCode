class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        vector<string> ans;
        int n = words.size();
        ans.push_back(words[0]);
        int val = 1 - groups[0];

        for (int i = 1; i < n; i++) {

            if (groups[i] != val)
                continue;
            else {
                ans.push_back(words[i]);
                val = 1 - groups[i];
            }
        }

        return ans;
    }
};