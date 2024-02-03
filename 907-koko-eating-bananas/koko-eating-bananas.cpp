class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            long long sum=0;
            for(int i=0;i<n;i++)
            {
                sum+=((piles[i]/mid)+(piles[i]%mid!=0)); //take ceil value basically
            }
            if(sum<=h)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};