class Solution {
public:
void buildExpr(vector<string>& res, string expr, string digits,
               int target, int idx, long long eval, long long last) {

    if (idx == digits.length()) {
        if (eval == target)
            res.push_back(expr);
        return;
    }

    for (int i = idx; i < digits.length(); i++) {
        
        // Skip numbers with leading zero
//         That line ensures we don’t generate substrings with leading zeros.
// Only a single "0" is valid, but nothing like "05", "0001", etc.
        if (i != idx && digits[idx] == '0') break;

        string part = digits.substr(idx, i - idx + 1);
        long long num = stoll(part);

        if (idx == 0) {
            buildExpr(res, part, digits, target, i + 1, num, num);
        } else {
            buildExpr(res, expr + "+" + part, digits, target, i + 1, eval + num, num);
            buildExpr(res, expr + "-" + part, digits, target, i + 1, eval - num, -num);
            buildExpr(res, expr + "*" + part, digits, target, i + 1,
                      eval - last + last * num, last * num);
        }
    }
}
    vector<string> addOperators(string num, int target) {
        vector<string> res;
    buildExpr(res, "", num, target, 0, 0, 0);
    return res;
    }
};