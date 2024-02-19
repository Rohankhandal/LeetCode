//Don't tell to interviewer
// using to constraints 2^31-1 means 2^31 is not include
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        int power=pow(2,30);
        return power%n==0;
    }
};



// //Approach-1 (Using normal division) - Can also wite iterative version
// //T.C : O(log(n))
// //S.C : O(1)
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n <= 0)
//             return false;
//         if(n == 1)
//             return true;
        
//         return n%2 == 0 && isPowerOfTwo(n/2);
//     }
// };

// //Approach-2 (Using bit magic)
// //T.C : O(1)
// //S.C : O(1)
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         return (n > 0) && ((n & (n - 1)) == 0);
//     }
// };
// // if n=>8=> 1000 if n is mutiple of 2 then & with n-1 equal to 0
// //    n-1=>7=>111
// //    -----------
// //           0000

// //Approach-2 (__builtin_popcount)
// //T.C : O(1)
// //S.C : O(1)
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n <= 0)
//             return false;
        
//         return __builtin_popcount(n) == 1;
//     }
// };


// // Using Recursion
// // class Solution {
// // public:
// //     bool isPowerOfTwo(int n) {
// //          if(n<=0) return false;
// //         if(n==1) return true;

// //         return n%2==0 && isPowerOfTwo(n/2);
// //     }
// // };