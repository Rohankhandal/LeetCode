class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long ans=-1;
        long long sum1=0;
        long long zero1=0;

        long long sum2=0;
        long long zero2=0;

        for(auto &it:nums1)
        {
            if(it!=0)
            sum1+=it;
            else zero1++,sum1+=1;
        }

        for(auto &it:nums2)
        {
            if(it!=0)
            sum2+=it;
            else zero2++,sum2+=1;
        }
        long long diff=sum1-sum2;
        
        if(diff==0) return sum1;
        if(diff>0)
        {
            if(zero2) ans=diff+sum2;
        }
        else 
        {
            if(zero1) ans=abs(diff)+sum1;
        }

        return ans;
    }
};