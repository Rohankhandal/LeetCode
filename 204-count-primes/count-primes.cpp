class Solution {
public:
    vector<bool> checkPrime(int n)
    {
        vector<bool>prime(n,true);
        prime[0]=false;
        prime[1]=false;

        for(int i=2;i<=sqrt(n);i++)
        {
            if(prime[i])
            {
                long long int j=i*i;
                while(j<n)
                {
                    prime[j]=false;
                    j+=i;
                }
            }
        }

        return prime;
    }
    int countPrimes(int n) {
        if(n<=1) return 0;

       vector<bool>prime=checkPrime(n);
       int ans=0;
       for(int i=0;i<n;i++){
        if(prime[i]==true) ans++;
       }   
       return ans;
    }
};