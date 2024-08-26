
class Solution {
public:
    // Function to calculate the length of a repeated character group starting from 'start' index
    int getLengthOfRepeated(string &s, int start) {
        int index = start;
        int cnt = 0;
        // Count how many times the character at 'start' repeats consecutively
        while (index < s.size() && s[index] == s[start]) {
            cnt++;
            index++;
        }
        return cnt; // Return the count of repeated characters
    }

    // Function to check if a word 'str' can be stretched to match string 's'
    bool isStretchy(string &s, string &str) {
        int i = 0, j = 0;
        int n = s.size();
        int m = str.size();

        while (i < n && j < m) {
            if (s[i] != str[j]) return false; // Characters don't match, not stretchy

            // Get the lengths of repeated characters in 's' and 'str'
            int len1 = getLengthOfRepeated(s, i);
            int len2 = getLengthOfRepeated(str, j);

            // Check if the group in 'str' is longer or if it can't be stretched in 's'
            if ((len1 < len2) || (len1 > len2 && len1 < 3))
                return false;

            // Move to the next group in both strings
            i += len1;
            j += len2;
        }

        // Ensure both strings have been fully compared
        return (i == n && j == m);     //bcz e.g s="abcd" and words=["abc"]
    }

    // Function to count how many words in 'words' are stretchy compared to 's'
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;

        for (auto &str : words) {
            if (str.size() > s.size()) continue; // Skip if word is longer than 's'
            if (isStretchy(s, str)) {
                ans++; // Increment count if the word is stretchy
            }
        }
        return ans; // Return the total count of stretchy words
    }
};
