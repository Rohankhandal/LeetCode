//Approach (Optimal)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xor_r = 0;

        for(int &num : nums) {
            xor_r ^= num;
        }

        //mask -> right most set bit search 
        int mask = (xor_r) & (-xor_r);
        /*
            It works because if you take the two's complement negation of a number, first you complement it,
            setting all zeroes to the right of the lowest set bit to one and the lowest set bit to zero,
            then you add one, setting the bits on the right to zero and the lowest set bit becomes one again, ending the carry chain.
        */

        int groupa = 0;
        int groupb = 0;

        for(int &num : nums) {
            if(num & mask) {
                groupa ^= num;
            } else {
                groupb ^= num;
            }
        }

        return {groupa, groupb};
    }
};