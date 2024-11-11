class Solution {
public:
    void sieve(vector<bool>&primes)
    {
        int n=primes.size();
        primes[0]=false;
        primes[1]=false;

        for(int i=2;i<n;i++)
        {
            if(primes[i]==false) continue;
            int j=2*i;
            while(j<n)
            {
                primes[j]=false;
                j+=i;
            }
        }
        // for(int i=2;i<n;i++)
        // {
        //     cout<<i<<" "<<primes[i]<<endl;
        // }
    }
    bool primeSubOperation(vector<int>& nums) {
        vector<bool>primes(10001,true);
        sieve(primes);
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                for(int j=nums[i]-1;j>=2;j--)
                {
                    if(primes[j])
                    {
                        nums[i]=nums[i]-j; 
                        break;
                    } 
                }
            }
            else
            {
                for(int j=nums[i]-1;j>=2;j--)
                {

                    if(primes[j] && (nums[i]-j)>nums[i-1])
                    {
                        nums[i]=nums[i]-j; 
                        break;
                    } 
                }
            }
        }
        // for(auto &it:nums) cout<<it<<" ";
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]<=nums[i-1]) return false;
        }
        return true;
    }
};