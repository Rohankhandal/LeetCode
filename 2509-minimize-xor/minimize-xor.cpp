class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = __builtin_popcount(num2); // Count set bits in num2
        int ans = 0;

        // Step 1: Set bits in `num1` from highest to lowest while cnt > 0
        for (int i = 31; i >= 0; i--) {
            if ((num1 & (1 << i)) && cnt > 0) {
                ans |= (1 << i);
                cnt--;
            }
        }

        // Step 2: Set remaining bits from lowest to highest
        for (int i = 0; i < 32 && cnt > 0; i++) {
            if ((ans & (1 << i)) == 0) {
                ans |= (1 << i);
                cnt--;
            }
        }

        return ans;
    }
};
