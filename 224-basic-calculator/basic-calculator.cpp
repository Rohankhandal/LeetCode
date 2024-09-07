class Solution {
public:
    int calculate(string s) {
        int result = 0;   // Current result of the expression
        int number = 0;   // Current number being processed
        int sign = 1;     // Current sign, 1 for positive, -1 for negative

        stack<int> st;    // Stack to store intermediate results and signs

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                continue;  // Skip spaces
            }

            // If the character is a digit, build the current number
            if (s[i] >= '0' && s[i] <= '9') {
                number = number * 10 + (s[i] - '0');
            }
            // If we encounter a '+' or '-', calculate the result for the previous number
            else if (s[i] == '-' || s[i] == '+') {
                result += sign * number;  // Apply the sign to the number and add to result
                number = 0;  // Reset the current number
                // Set the new sign based on the operator
                sign = (s[i] == '-') ? -1 : 1;
            }
            // If we encounter '(', push the current result and sign to the stack
            else if (s[i] == '(') {
                st.push(result);  // Store the result before parentheses
                st.push(sign);    // Store the sign before parentheses
                // Reset for new sub-expression
                sign = 1;
                result = 0;
            }
            // If we encounter ')', process the current sub-expression
            else if (s[i] == ')') {
                result += sign * number;  // Add the last number within the parentheses
                number = 0;  // Reset current number

                int prevSign = st.top();  // Retrieve the sign before parentheses
                st.pop();
                int prevResult = st.top();  // Retrieve the result before parentheses
                st.pop();
                // Update the result by combining the result inside parentheses
                result = prevResult + prevSign * result;
            }
        }

        // In case there's a leftover number, add it to the result
        if (number != 0) result += sign * number;

        return result;
    }
};