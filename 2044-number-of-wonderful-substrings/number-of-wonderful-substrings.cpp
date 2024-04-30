//T.C : O(n)
//S.C : O(1)
typedef long long ll;
class Solution {
public:
    
    long long wonderfulSubstrings(string word) {
        unordered_map<ll, ll> mp;

        mp[0] = 1;
        int cum_xor = 0;

        ll result = 0;


        for(char &ch : word) {

            int shift = ch - 'a';

            cum_xor ^= (1 << shift);

            result += mp[cum_xor];  //for even no. of occurrence

            for(char ch1 = 'a' ; ch1 <= 'j'; ch1++) {
                shift = ch1 - 'a';

                ll check_xor = (cum_xor ^ (1 << shift));  // for 1 letter apperas odd no. of times

                result += mp[check_xor];
            }

            mp[cum_xor]++;

        }

        return result;
    }
};