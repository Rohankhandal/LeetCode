// t.c:-O(nLogn)
class Solution {
public:
    bool check(string s, int k) {  //O(n+k)=>O(N)
        int n = s.size();
        char firstFreq[26] = {0};
        for (int i = 0; i < k; i++) {  //o(K)
            firstFreq[s[i] - 'a']++;
        }

        for (int i = k; i < n; i += k) {  //O(n/k)
            char rangeFreq[26] = {0};
            for (int j = i; j < k + i; j++) {  //O(K)
                rangeFreq[s[j] - 'a']++;
            }
            for (int i = 0; i < 26; i++) { //O(26)
                if (firstFreq[i] != rangeFreq[i])
                    return false;
            }
        }//O(N)
        return true;
    }
    int minAnagramLength(string s) {
        int n = s.size();
        for (int i = 1; i <= n; i++) {  //O(~logN)
            if (n % i == 0 && check(s, i)) {  
                return i;
            }
        }
        return -1;
    }
};