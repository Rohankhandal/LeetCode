// class Solution {
// public:
//     int partitionString(string s) {
//         unordered_map<char,int>mp;
//         int n=s.size();
//         int ans=1;
//         for(int i=0;i<n;i++){
//             if(mp.find(s[i])!=mp.end())
//             {
//                 ans++;
//                 mp.clear();
//             }
//             mp[s[i]]++;
//         }   
//         return ans;
//     }
// };


class Solution {
public:
    int partitionString(string s) {
        vector<int> lastSeen(26, -1);
        
        int count = 0;
        int substringStart = 0;

        for (int i = 0; i < s.length(); i++) {
            if (lastSeen[s[i] - 'a'] >= substringStart) {
                count++;
                substringStart = i;
            }
            lastSeen[s[i] - 'a'] = i;
        }

        return count+1;
    }
};