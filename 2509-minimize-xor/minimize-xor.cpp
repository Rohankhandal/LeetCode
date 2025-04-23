class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBits = __builtin_popcount(num2);
        vector<int> result(32, 0);

        // Step 1: Try to match set bits of num1 from MSB to LSB
        for (int i = 31; i >= 0 && setBits > 0; --i) {
            if (num1 & (1 << i)) {
                result[i] = 1;
                --setBits;
            }
        }

        // Step 2: If set bits still remain, fill from LSB to MSB
        for (int i = 0; i < 32 && setBits > 0; ++i) {
            if ((num1 & (1 << i)) == 0) {
                result[i] = 1;
                --setBits;
            }
        }

        // Step 3: Construct the result from bits
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            if (result[i]) {
                ans |= (1 << i);
            }
        }

        return ans;
    }
};
