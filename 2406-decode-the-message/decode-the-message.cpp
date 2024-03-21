class Solution {
public:
    string decodeMessage(string key, string message) {

        // create substitution table using map array(create mapping)
        char map[1000] = {0};
        char start = 'a';

        for (auto k : key) {
            if (map[k] == 0 && k != ' ') {
                map[k] = start;
                start++;
            }
        }

        string ans;

        // use substitution table(use mapping)
        for (auto m : message) {
            if (m == ' ')
                ans.push_back(m);
            else {
                char ch = map[m];
                ans.push_back(ch);
            }
        }
        return ans;
    }
};