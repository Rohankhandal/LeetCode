
class Solution {
public:
    int longestSubstring(string s, int k) {

        int n = s.length();
        if (n == 0 || n < k)
            return 0;
        if (k <= 1)
            return n;

        unordered_map<char, int> counts;
        for (char c : s)
            counts[c] += 1; // count frequency

        int l = 0;
        while (l < n && counts[s[l]] >= k)
            l++;
        if (l >= n - 1)
            return l;

        int ls1 = longestSubstring(s.substr(0, l), k);
        while (l < n && counts[s[l]] < k)
            l++;
        int ls2 = (l < n) ? longestSubstring(s.substr(l), k) : 0;
        return max(ls1, ls2);
    }
};

// Time complexity:O(n2)

// class Solution {
// public:
//     #define MAX 26

//     // Function that return true if frequency
//     // of all the present characters is at least k
//     bool atLeastK(int freq[], int k)
//     {
//         for (int i = 0; i < MAX; i++) {

//             // If the character is present and
//             // its frequency is less than k
//             if (freq[i] != 0 && freq[i] < k)
//                 return false;
//         }

//         return true;
//     }

//     void setZero(int freq[])
//     {
//         for (int i = 0; i < MAX; i++)
//             freq[i] = 0;
//     }

//     int longestSubstring(string s, int k) {
//         int n=s.length();
//         int maxLen = 0;

//         int freq[MAX];

//         // Starting index of the sub-string
//         for (int i = 0; i < n; i++) {
//             setZero(freq);

//             // Ending index of the sub-string
//             for (int j = i; j < n; j++) {
//                 freq[s[j] - 'a']++;

//                 // If the frequency of every character
//                 // of the current sub-string is at least k
//                 if (atLeastK(freq, k)) {

//                     // Update the maximum possible length
//                     maxLen = max(maxLen, j - i + 1);
//                 }
//             }
//         }

//         return maxLen;
//     }
// };