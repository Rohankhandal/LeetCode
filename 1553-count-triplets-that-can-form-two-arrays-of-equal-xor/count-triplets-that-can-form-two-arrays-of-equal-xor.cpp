class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        vector<int>v(n+1,0);
        for(int i=0;i<n;i++)
        {
            v[i+1]=v[i]^arr[i];
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int k=i+1;k<n+1;k++)
            {
                if(v[i]==v[k])
                 ans+=(k-i-1);
            }
        }

        return ans;
    }
};