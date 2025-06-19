class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> right(26, 0);

        for (int i = 0; i < n; i++) {
            right[s[i] - 'a']++;
        }

        vector<int> left(26, 0);
        unordered_set<string> seen;
        int cnt = 0;

        left[s[0] - 'a']++;
        right[s[0] - 'a']--;

        for (int i = 1; i < n; i++) {
            right[s[i] - 'a']--;

            for (int ch = 0; ch < 26; ch++) {
                if (left[ch] > 0 && right[ch] > 0) {
                    string pattern = string(1, ch + 'a') + s[i] + string(1, ch + 'a');
                    if (!seen.count(pattern)) {
                        cnt++;
                        seen.insert(pattern);
                    }
                }
            }

            left[s[i] - 'a']++;
        }

        return cnt;
    }
};
