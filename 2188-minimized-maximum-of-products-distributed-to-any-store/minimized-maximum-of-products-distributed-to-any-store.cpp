class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxi=*max_element(quantities.begin(),quantities.end());
    
        int l=1,r=maxi;
        int ans=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            //check is mid is correct for all products
            int i=1;
            for(auto it:quantities)
            {
                while(it>0)
                {
                    it-=mid;
                    i++;
                }
            }
            // cout<<mid<<" "<<i<<endl;
            if(i<=n+1)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};