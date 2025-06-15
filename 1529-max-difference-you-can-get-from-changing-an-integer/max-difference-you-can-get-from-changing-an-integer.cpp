class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        // Step 1: maximize number by replacing first digit != '9' with '9'
        string maxStr = s;
        for (char& c : maxStr) {
            if (c != '9') {
                char x = c;
                for (char& ch : maxStr) {
                    if (ch == x) ch = '9';
                }
                break;
            }
        }

        // Step 2: minimize number by replacing first digit != '1'/'0'
        string minStr = s;
        if (minStr[0] != '1') {
            char x = minStr[0];
            for (char& ch : minStr) {
                if (ch == x) ch = '1';
            }
        } else {
            for (int i = 1; i < minStr.size(); i++) {
                if (minStr[i] != '0' && minStr[i] != '1') {
                    char x = minStr[i];
                    for (int j = i; j < minStr.size(); j++) {
                        if (minStr[j] == x) minStr[j] = '0';
                    }
                    break;
                }
            }
        }

        int a = stoi(maxStr);
        int b = stoi(minStr);
        return a - b;
    }
};
