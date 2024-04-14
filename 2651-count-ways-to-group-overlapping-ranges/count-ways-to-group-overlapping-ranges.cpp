int M=1e9+7;
class Solution {
public:
    long long  power(long long  x,long long  y)   //=>x =no. && y=power
    {
        long long ans=1;
        while(y>0)
        {
            if(y&1)  //odd number
            {
                ans=(ans*x)%M; 
            }
            x=(x*x)%M;

            y>>=1;  //y=y/2 right shift
        }
        return ans%M;
    }
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(),ranges.end());
        int overlap=1;
        int prevEnd=ranges[0][1];
        int bucket=1;
        // for(auto &it:ranges)
        // {
        //     cout<<it[0]<<" "<<it[1]<<endl;
        // }
        for(int i=1;i<ranges.size();i++)
        {
            if(ranges[i][0]<=prevEnd)  //overLapping
            {
               prevEnd=max(ranges[i][1],prevEnd);
                
            }
            else
            {
                bucket++;
                prevEnd=ranges[i][1];
            }
           
        }
        // return (long long)pow(2,bucket);
        return power(2,bucket)%M;
    }
};