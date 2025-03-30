class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, -1);
        vector<int> ans;
        int n = s.size();
        
       
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }
        
       
        int end = 0, start = 0;
        for (int i = 0; i < n; i++) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) {
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }
        
        return ans;
    }
};
