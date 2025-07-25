// If all numbers are negative: return the maximum among them.

// If some numbers are positive: return sum of all positive distinct values.
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> unique;
        bool hasPositive = false;
        int maxNeg = INT_MIN;
        int sum = 0;

        for (int num : nums) {
            unique.insert(num);
            if (num > 0) hasPositive = true;
            if (!hasPositive) maxNeg = max(maxNeg, num);
        }

        if (!hasPositive) return maxNeg;

        for (int num : unique) {
            if (num > 0) sum += num;
        }

        return sum;
    }
};
