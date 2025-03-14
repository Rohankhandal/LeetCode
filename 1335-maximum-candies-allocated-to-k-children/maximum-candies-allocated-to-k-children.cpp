class Solution {
public:
    int maximumCandies(vector<int>& c, long long k) {
        int m = 0;
        for (int i = 0; i < c.size(); i++) {
            m = max(m, c[i]);
        }

        int l = 0, r = m;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (canAllocateCandies(c, k, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }

        return l;
    }

private:
    bool canAllocateCandies(vector<int>& c, long long k, int n) {
        long long t = 0;
        for (int i = 0; i < c.size(); i++) {
            t += c[i] / n;
        }
        return t >= k;
    }
};
