class Solution {
public:
    double power(double x, long long n) { // Using long long for larger values of n
        double ans = 1;
        while (n) {
            if (n & 1) {
                ans *= x;
            }
            x *= x; // Storing x * x for optimization
            n >>= 1;
        }
        return ans;
    }

    double myPow(double x, int n) {
        if (n == 0) return 1; // Handle n == 0 case
        if (n < 0) {
            x = 1 / x;
            // n = -n;
        }
        return power(x, abs(n));
    }
};
