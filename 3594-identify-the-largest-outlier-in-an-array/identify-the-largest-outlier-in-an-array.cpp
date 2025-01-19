class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        long long totalSum = 0;
        unordered_map<int, int> freqMap;

        for (int num : nums) {
            totalSum += num;
            freqMap[num] += 1;
        }

        int maxOutlier = INT_MIN;
        for (int num : nums) {
            long long requiredSum = totalSum - num;
            if (requiredSum % 2 != 0) continue;

            long long potentialSum = requiredSum / 2;
            freqMap[num] -= 1;
            int sumElement = static_cast<int>(potentialSum);
            int count = freqMap.count(sumElement) ? freqMap[sumElement] : 0;
            if (count > 0) maxOutlier = max(maxOutlier, num);
            freqMap[num] += 1;
        }

        return maxOutlier;
    }
};