class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        //first find all prime number
        vector<int>primes;
        vector<int>mark(right+1,true);

        //apply seive of erathoneoues
        for(int i=2;i*i<=right;i++)
        {
            if(mark[i])
            {
                for(int j=2;j*i<=right;j++)
                {
                    mark[i*j]=false;
                }
            }
        }

        //store prime number in primes vector
        for(int i=max(2,left);i<=right;i++)
        {
            if(mark[i])
            {
                primes.push_back(i);
            }
        }

        //now find the 2 closest prime diff    [we take closest bcz diff is minimized in case of closest prime]
        int a=0;
        int b=INT_MAX;
        for(int i=1;i<primes.size();i++)
        {
            if(primes[i]-primes[i-1] < b-a)
            {
                a=primes[i-1];
                b=primes[i];
            }
        }
        vector<int>ans;
        if(a==0)
        {
            ans={-1,-1};
        }
        else {
            ans.push_back(a);
            ans.push_back(b);
        }

        return ans;
    }
};