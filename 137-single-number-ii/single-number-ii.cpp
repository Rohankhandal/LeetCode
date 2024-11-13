class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitArr(32, 0);
        for (int num : nums) {
            for (int i = 0; i < 32; i++) {
                if (num & (1 << i)) {
                    bitArr[i]++;
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < 32; i++) {
            bitArr[i] %= 3;
            ans += bitArr[i] * pow(2,i)*1LL;
        }
        return static_cast<int>(ans);
    }
};