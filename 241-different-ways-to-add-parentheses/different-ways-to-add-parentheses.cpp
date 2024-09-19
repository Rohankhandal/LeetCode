class Solution {
public:
  
    
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        int n = expression.size();

        // Base case: if the string is empty, return an empty list
        if (expression.length() == 0) return ans;

        // Base case: if the string is a single character, treat it as a number
        // and return it
        if (expression.length() == 1) {
            ans.push_back(stoi(expression));
            return ans;
        }

        // If the string has only two characters and the first character is a
        // digit, parse it as a number
        if (expression.length() == 2 && isdigit(expression[0])) {
            ans.push_back(stoi(expression));
            return ans;
        }
        
        for (int i = 0; i < n; i++) {
            char ch = expression[i];
            if (ch == '+' || ch == '-' || ch == '*') {
                vector<int> left =   diffWaysToCompute(expression.substr(0, i));
                vector<int> right =   diffWaysToCompute(expression.substr(i+1));

                for (auto &l : left) {
                    for (auto &r : right) {
                        if (ch == '+')
                            ans.push_back(l + r);
                        else if (ch == '-')
                            ans.push_back(l - r);
                        else if (ch == '*')
                            ans.push_back(l * r);
                    }
                }
            }
        }
        
        // If ans is empty, then the expression itself is just a number
        if (ans.empty()) {
            ans.push_back(stoi(expression));
        }
        
        return ans;
    }
};
