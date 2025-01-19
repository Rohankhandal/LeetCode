class Solution {
public:
    long long smallestNumber(long long num) {
        long long ans=0;
        vector<int>arr;
        bool neg=false;;
        if(num<0) neg=true;

        long long temp=num;
        int zero=0;
        while(temp)
        {
            long long bit=temp%10;
            if(bit==0) zero++;
            else
            arr.push_back(abs(bit));

            temp=temp/10;
        }
        if(neg)
        {
            sort(arr.rbegin(),arr.rend());

            // for(auto &it:arr) cout<<it<<" ";

            for(auto &it:arr)
            {
                ans=ans*10+it;
            }
            while(zero){
                ans=ans*10;
                zero--;
            }
            return -ans;
        }
        else
        sort(arr.begin(),arr.end());

        bool first=true;
        for(auto &it:arr)
        {
            ans=ans*10+it;
            while(zero&&first)
            {
                ans=ans*10; 
                zero--;  
            }
            first=false;
        }
        return ans;

        




    }
};