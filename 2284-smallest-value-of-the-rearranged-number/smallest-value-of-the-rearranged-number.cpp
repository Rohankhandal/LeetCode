class Solution {
public:
    long long smallestNumber(long long num) {
        if (num < 0) {
            // Handle negative numbers
            string s = to_string(-num);  // Convert absolute value to string
            sort(s.begin(), s.end(), greater<char>());  // Sort in descending order
            return -stoll(s);  // Convert back to long long and negate
        } else {
            // Handle non-negative numbers
            string s = to_string(num);  // Convert to string
            sort(s.begin(), s.end());  // Sort in ascending order
            
            // Find the first non-zero digit and swap with the leading digit
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] != '0') {
                    swap(s[0], s[i]);
                    break;
                }
            }
            return stoll(s);  // Convert back to long long
        }
    }
};
