class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = *max_element(quantities.begin(), quantities.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int requiredStores = 0;

            for (int quantity : quantities) {
                requiredStores += (quantity + mid - 1) / mid; // calculates ceiling of quantity/mid
            }

            if (requiredStores <= n) {
                ans = mid;    // possible solution, try for a smaller max quantity
                right = mid - 1;
            } else {
                left = mid + 1; // too few stores, increase mid to reduce the load
            }
        }

        return ans;
    }
};
