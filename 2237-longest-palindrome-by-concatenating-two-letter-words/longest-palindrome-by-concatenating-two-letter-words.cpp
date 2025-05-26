class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for (auto &it : words) {
            mp[it]++;
        }

        int ans = 0;
        bool hasMiddle = false;

        for (auto &it : mp) {
            string s = it.first;
            int freq = it.second;
            string rev = s;
            reverse(rev.begin(), rev.end());

            if (s == rev) {
                // Self-palindromic strings like "aa", "bb"
                ans += (freq / 2) * 2;
                if (freq % 2 == 1) hasMiddle = true;
            } else if (mp.find(rev) != mp.end()) {
                int pairs = min(freq, mp[rev]);
                ans += pairs * 2;
                mp[rev] = 0; // mark reverse as used
                mp[s] = 0;   // mark current as used
            }
        }

        if (hasMiddle) ans += 1; // one self-palindromic word in the center

        return ans * 2; // each word is 2 letters
    }
};
