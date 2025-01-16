class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0, xor2 = 0;
        
        // XOR of all elements in nums1
        for (int num : nums1) {
            xor1 ^= num;
        }

        // XOR of all elements in nums2
        for (int num : nums2) {
            xor2 ^= num;
        }
// Parity Check:
//     If the size of nums2 is odd, each element in nums1 contributes once to the result (since n⊕n==0 when appearing an even number of times).
//     Similarly, if the size of nums1 is odd, each element in nums2 contributes once to the result.

        // The result depends on the parity of nums1.size() and nums2.size()
        int ans = 0;
        if (nums2.size() % 2 == 1) {
            ans ^= xor1; // Add all elements of nums1
        }
        if (nums1.size() % 2 == 1) {
            ans ^= xor2; // Add all elements of nums2
        }

        return ans;
    }
};
