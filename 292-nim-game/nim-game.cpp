/* Approach : Math
n % (a+b) == 0 --> Lose
n % (a+b) != 0 --> Win
Time : O(1)
Space : O(1)
*/

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};