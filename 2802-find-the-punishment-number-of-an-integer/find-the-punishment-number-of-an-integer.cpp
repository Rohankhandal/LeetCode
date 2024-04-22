class Solution {
private:
    bool is_valid(int i, string s, int t) {
        if(i == s.size() && t == 0) return true;
        else if(i == s.size()) return false;

        string temp = "";
        bool ans = false;
        for(int ind = i; ind < s.size(); ind++) {
            temp += s[ind];
            ans = ans || is_valid(ind+1, s, t - stoi(temp));
            // if(ans) return true;
        }

        return ans;
    }

public:
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++) {
            if(is_valid(0, to_string(i*i), i)) {
                ans += i*i;
                cout<<i*i<<endl;
            }
        }

        return ans;
    }
};