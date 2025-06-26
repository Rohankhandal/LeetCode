class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int count = 0;
        long long val = 0;
        int bit = 0;

        // Traverse from the right (LSB side)
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                count++; // zero adds nothing, always safe
            } else {
                if (bit < 32 && (val + (1LL << bit)) <= k) {
                    val += (1LL << bit);
                    count++;
                }
            }
            bit++;
        }

        return count;
    }
};
