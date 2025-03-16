class Solution {
public:
    typedef long long ll;

    bool isPossible(vector<int>& ranks, int cars,ll mid) {
        ll carsFixed = 0;

        for(int i = 0; i < ranks.size(); i++) {
            carsFixed += sqrt(mid/ranks[i]); //ignoring this
        }
        return carsFixed >= cars;

    }
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(),ranks.end());
        int mini=*min_element(ranks.begin(),ranks.end());
        long long  l=mini;
        long long  r=mini*1LL*cars*1LL*cars;
        long long ans=0;

        while(l<=r)
        {
            long long  mid=(l+r)/2;

            if(isPossible(ranks,cars,mid))
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