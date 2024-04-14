class Solution {
public:
    int hammingWeight(int n) {
        int setBits=0;
        while(n)
        {
            setBits+=(n&1);
            n>>=1;
        }
        return setBits;
    }
};