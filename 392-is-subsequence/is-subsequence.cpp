// Follow up question
//Time : O(s.length() * log(n))
// class Solution {
// public:
//     int numMatchingSubseq(string s, vector<string>& words) {
//         map<char, vector<int>> mp;
//         int n = s.length();
        
//         for(int i = 0; i<n; i++) {
//             mp[s[i]].push_back(i);
//         }

//         int count = 0;
//         for(string &word : words) {
//             int prev      = -1;
//             bool found = true;

//             for(char &ch : word) {
//                 if(mp.find(ch) == mp.end()) {
//                     found = false;
//                     break;
//                 }

//                 auto it = upper_bound(begin(mp[ch]), end(mp[ch]), prev); //Binary Search (O(log(n))
                
//                 if(it == mp[ch].end()) {
//                     found = false;
//                     break;
//                 }

//                 prev = *it;
//             }
//             if(found)
//                 count++;
//         }
//         return count;
//     }
// };


class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len1=s.size();
        int n=t.size();
        int j=0;
        if(len1==0) return true;
        for(int i=0;i<n;i++)
        {
            if(t[i]==s[j])
            {
                j++;
                if(j==len1) return true;
            }

        }
        return false;
    }
};