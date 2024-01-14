// 942. DI String Match
// https://leetcode.com/problems/di-string-match/
// Difference between push_back and emplance_back
class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> result;
        int n = s.size();
        result.reserve(n + 1);
        int l = 0, r = n;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'I') result.emplace_back(l++);
            else result.emplace_back(r--);
        }
        // l is equal to r
        result.emplace_back(l);

        return result;
    }
};

// using push_back
// class Solution {
// public:
//     vector<int> diStringMatch(string s) {
//         int n=s.size();
//         vector<int>ans;
//         int l=0,r=n;
//         for(int i=0;i<n;i++)
//         {
//             if(s[i]=='I')
//             {
//                  ans.push_back(l);
//                  l++;
//             }
//             else
//             {
//             ans.push_back(r);
//             r--;
//             }
//         }
//         ans.push_back(l);
//         return ans;
//     }
// };