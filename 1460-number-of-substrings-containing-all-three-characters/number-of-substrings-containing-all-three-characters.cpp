class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();  // String length
        vector<int> freq(3, 0);  // Frequency of 'a', 'b', 'c'
        int ans = 0;  // Result count
        int start = 0, end = 0;  // Sliding window pointers

        while (end < n) {
            freq[s[end] - 'a']++;  // Add char at 'end'

            // Shrink window when all three chars are present
            while (freq[0] >= 1 && freq[1] >= 1 && freq[2] >= 1) {
                ans += (n - end);  // Count valid substrings
                freq[s[start] - 'a']--;  // Remove char at 'start'
                start++;  // Move 'start' right
            }

            end++;  // Move 'end' right
        }
        return ans;  // Return the count
    }
};