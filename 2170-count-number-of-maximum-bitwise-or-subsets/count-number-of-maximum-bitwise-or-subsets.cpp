class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = INT_MIN;
        unordered_map<int, int> mp;
        for (int i = 1; i < pow(2, n); i++) {
            int res = 0;
            int j = i;
            int idx = 0;
            while (j) {
                if (j & 1) {
                    res |= nums[idx];
                    if (res > maxOr) {
                        maxOr = res;
                    }
                }
                idx++;
                j >>= 1;
            }
            mp[res]++;
        }
        cout << maxOr;
        return mp[maxOr];
    }
};