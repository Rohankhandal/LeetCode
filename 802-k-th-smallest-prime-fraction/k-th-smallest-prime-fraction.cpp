class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        map<double,pair<int,int>>frac;
        int n=arr.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double div=(double)arr[i]/(double)arr[j];
                frac[div]={arr[i],arr[j]};
            }
        }
        // sort(frac.begin(),frac.end());
        vector<int>ans(2);
        int cnt=0;
        for(auto &it:frac)
        {
            // cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
            cnt++;
            if(cnt==k)
            {
                ans[0]=it.second.first;
                ans[1]=it.second.second;
                break;
            }
        }
        return ans;
    }
};