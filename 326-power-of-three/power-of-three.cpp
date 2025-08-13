// n=3^i ; where i=>interger
// take log3 both side
// log3(n)=log3(3^i);
// log3(n)=i*1;
// so i=log10(n)/log10(3);   //if i is interger then true

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        double logValue = log10(n) / log10(3);
        return logValue == (int)logValue;  //if logValue is interger then, true
    }
};



// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         if(n==0) return false;
//         if(n==1) return true;

//         return (n>0 && (n%3==0) && isPowerOfThree(n/3));
//     }
// };