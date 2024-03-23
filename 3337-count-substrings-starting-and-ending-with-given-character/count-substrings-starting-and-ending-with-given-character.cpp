//Approach-1 (Straight forward count)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count = 0;   //it count the no. of occurrence of char c
        long long substrings = 0;
        

        for(char &ch : s) {
            if(ch == c) {
                substrings += (1 + count);   //1(bcz indivdual char is also substring of itself)+count(in past how 
                //how many occurrence we see to make a substring)
                count++;
            }
        } 
        return substrings;
    }
};

// class Solution {
// public:
//     long long countSubstrings(string s, char c) {
//         int n=s.size();
//         long long  freq=0;
//         for(auto &it:s) 
//         {
//             if(it==c) freq++;
//         }
//         long long ans=freq*(freq+1)/2;
//         return ans ;
//     }
// };