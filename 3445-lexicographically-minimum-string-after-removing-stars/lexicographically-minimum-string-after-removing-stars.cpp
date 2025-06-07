class Solution {
public:
    typedef pair<char, int> P;

    struct comp {
        bool operator()(P &p1, P &p2) {
            if (p1.first == p2.first) {  //if the character are same then it must lexigrophically smaller , so we have to delete last chracter from right end
                return p1.second < p2.second;
            }
            return p1.first > p2.first;  //else delete small character from left end(so sort according to this)
        }
    };

    string clearStars(string s) {
        priority_queue<P, vector<P>, comp> pq;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                if (!pq.empty()) {
                    auto top = pq.top();
                    pq.pop();
                    int idx = top.second;
                    s[idx] = '*';  // Mark the character to be removed
                }
            } else {
                pq.push({s[i], i});
            }
        }

        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};