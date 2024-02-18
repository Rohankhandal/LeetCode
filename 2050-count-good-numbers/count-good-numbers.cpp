#define mod 1000000007
class Solution {
public:
    long long power(long long x,long long y)   //T.c:-O(logN)  S.c:-O(logN) (recusion call stack)
    {
        if(y==0) return 1;

        long long ans=power(x,y/2);
        ans*=ans;  //ans=(x,y/2)*(x,y/2)
        ans%=mod;

        if(y%2) ans*=x; //(x,7) =(x,3)*(x,3)*x
        ans%=mod;
        return  ans;
    }
    int countGoodNumbers(long long n) {
        long long odd=n/2;
        long long even=n/2+n%2;

        return (power(5,even)* power(4,odd))%mod;  //we have define our own power function 
        // otherwise , we get TLE
    }
};