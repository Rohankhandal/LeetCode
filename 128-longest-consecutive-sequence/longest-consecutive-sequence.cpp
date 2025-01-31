class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end()); // Insert all elements into a set
        int maxLen = 0;

        for (int num : s) {
            if (s.find(num - 1) == s.end()) { // Start counting only if it's the start of a sequence
                int currentNum = num;
                int count = 0;

                while (s.find(currentNum) != s.end()) { // Count consecutive elements
                    currentNum++;
                    count++;
                }

                maxLen = max(maxLen, count);
            }
        }

        return maxLen;
    }
};
