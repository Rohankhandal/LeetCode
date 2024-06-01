class Solution {
public:
    void solve(string s, vector<string>& ans, string temp, unordered_map<string, int>& mp, int i) {
        if (i >= s.size()) {
            // Remove the trailing space and add the temp string to the answer list
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        for (int l = 1; l <= s.size() - i; l++) {
            string str = s.substr(i, l);
            if (mp.find(str) != mp.end()) {
                // Save the current state of temp before modification
                string newTemp = temp + str + " ";
                solve(s, ans, newTemp, mp, i + l);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        unordered_map<string, int> mp;
        for (auto& it : wordDict) {
            mp[it]++;
        }
        string temp;
        solve(s, ans, temp, mp, 0);
        return ans;
    }
};
