//Approach-2 (Using DP + Backtracking)
//T.C : O(2^n)
//S.C : O(n^2)
class Solution {
public:
    // Backtracking function to generate all palindrome partitions
    void solve(string &s, int i, vector<string>& currPartition, vector<vector<bool>>& t, vector<vector<string>>& result) {
        if(i == s.length()) { // Base case: successfully partitioned the entire string
            result.push_back(currPartition);
            return;
        }
        for(int j = i; j < s.length(); j++) {
            if(t[i][j] == true) { // If s[i...j] is a palindrome
                currPartition.push_back(s.substr(i, j-i+1));
                solve(s, j+1, currPartition, t, result); // Recurse for the rest of the string
                currPartition.pop_back(); // Backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
       
        vector<vector<bool>> t(n, vector<bool>(n, false));
      	 // Initialize the DP table for palindromic substrings
        //t[i][j] = true -> s[i...j] is a palindrome  
      
        // Initialize: single characters are palindromes
        for (int i = 0; i < n; ++i) {
            t[i][i] = true;
        }
        
        // Fill the DP table
        for (int L = 2; L <= n; ++L) {
            for (int i = 0; i < n - L + 1; ++i) {
                int j = i + L - 1;
                if (s[i] == s[j]) {
                    if (L == 2) {
                        t[i][j] = true;
                    } else {
                        t[i][j] = t[i + 1][j - 1];
                    }
                }
            }
        }

        vector<vector<string>> result;
        vector<string> currPartition;
        solve(s, 0, currPartition, t, result);
        return result;
    }
};




//T.c:- O(n*2^n)
// class Solution {
// public:
//     bool isPalindrome(string&s,int l,int r)
//     {
//         cout<<s<<endl;
//         while(l<r)
//         {
//             if(s[l]!=s[r]) return false;
//             l++;r--;
//         }
//         return true;
//     }
//     void solve(vector<vector<string>>&ans,vector<string>temp,int idx,string&s)
//     {
//         if(idx>=s.size())
//         {
//             ans.push_back(temp);
//             return ;
//         }
//         for(int i=idx;i<s.size();i++)
//         {
//             // string str=s.substr(i,i-idx+1);

//             if(isPalindrome(s,idx,i))
//             {
//                 temp.push_back(s.substr(idx,i-idx+1));
//                 solve(ans,temp,i+1,s);
//                 temp.pop_back();
//             }
//         }
        
//     }
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>>ans;
//         vector<string>temp;
//         int i=0;
//         solve(ans,temp,i,s);
//         return ans;
//     }
// };