class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false; // A valid string must have an even length.

        // Check balance from left to right
        int open = 0, flexible = 0;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') {
                flexible++;
            } else if (s[i] == '(') {
                open++;
            } else { // s[i] == ')'
                if (open > 0) {
                    open--;
                } else if (flexible > 0) {
                    flexible--;
                } else {
                    return false; // No way to balance this closing parenthesis.
                }
            }
        }

        // Check balance from right to left
        int close = 0;
        flexible = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '0') {
                flexible++;
            } else if (s[i] == ')') {
                close++;
            } else { // s[i] == '('
                if (close > 0) {
                    close--;
                } else if (flexible > 0) {
                    flexible--;
                } else {
                    return false; // No way to balance this opening parenthesis.
                }
            }
        }

        return true;
    }
};
