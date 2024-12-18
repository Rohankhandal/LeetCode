class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        
        unordered_map<char, int> mp;
        int n = s.size();
        int start = 0;
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            // If the character is already in the map and its index is >= start, move the start
            if (mp.find(s[i]) != mp.end() && mp[s[i]] >= start) {
                start = mp[s[i]] + 1;  // Move start just after the previous occurrence of s[i]
            }
            
            // Update the character's latest index in the map
            mp[s[i]] = i;
            
            // Calculate maxLen with the current window size
            maxLen = max(maxLen, i - start + 1);
        }
        
        return maxLen;
    }
};
