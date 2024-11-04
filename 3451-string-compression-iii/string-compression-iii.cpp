class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int i = 0;
        int n = word.size();
        
        while (i < n) {
            char ch = word[i];
            int cnt = 0;
            
            while (i < n && word[i] == ch) {
                cnt++;
                i++;
            }
            
            while (cnt > 0) {
                int take = min(cnt, 9);
                ans += to_string(take) + ch;
                cnt -= take; 
            }
        }
        return ans;
    }
};