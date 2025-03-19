/* Approach : Math
If N is odd -> Win
If N is even -> Lose
Time : O(1)
Space : O(1)
*/
class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};