class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        int maxSize = 0;

        for (int i = 1; i <= n; i++) {
            int sum = 0, num = i;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            mp[sum]++;
            maxSize = max(maxSize, mp[sum]);
        }

        int ans = 0;
        for (auto &it : mp) {
            if (it.second == maxSize)
                ans++;
        }
        return ans;
    }
};
