
class Solution {
public:
int M=1e9+7;
    long long power(long long x,long long n)
    {
        long long ans=1;
        while(n>0)
        {
            if(n&1)
            {
                ans=(ans*x)%M;
            }

            x=(x*x)%M;
            n>>=1;
        }
        return ans%M;
    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;

        return (power((long long)5,even)*power((long long)4,odd))%M;
    }
};