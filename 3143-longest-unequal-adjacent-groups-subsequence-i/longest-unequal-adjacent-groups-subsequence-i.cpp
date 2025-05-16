class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        vector<string> ans;

        int startIdx = 0;
        int maxLen = 1;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            int val = 1 - groups[i];
            int len = 1;
            for (int j = i + 1; j < n; j++) {
                if (groups[j] != val)
                    continue;
                else {
                    len++;
                    val = 1 - groups[j];
                }
            }
            if (len > maxLen) {
                cout<<i<<endl;
                startIdx = i;
                maxLen = len;
            }
        }

        int len = 1;
        ans.push_back(words[startIdx]);
        int val = 1-groups[startIdx];
        for (int j = startIdx + 1; j < n; j++) {

            
            if (groups[j] != val)
                continue;
            else {
                ans.push_back(words[j]);
                val = 1 - groups[j];
            }
        }
        return ans;
    }
};