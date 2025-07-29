class Solution {
public:
    void merge(vector<pair<int,int>>&v,int l,int mid,int r,vector<int>&ans)
    {
        int n1=mid-l+1;
        int n2=r-mid;

        vector<pair<int,int>>dummy(n1+n2);

        int i=l,j=mid+1;
        int k=0;
        while(i<=mid && j<=r)
        {
            if(v[i].first<=v[j].first)
            {
                dummy[k++]=v[j];
                j++;
            }
            else{
                ans[v[i].second]+=(r-j+1);
                dummy[k++]=v[i];
                i++;
            }
        }

        while(i<=mid)
        {
            dummy[k++]=v[i];
            i++;
        }
        while(j<=r)
        {
            dummy[k++]=v[j];
            j++;
        }
        k=0;

        for(int i=l;i<=r;i++)
        {
            v[i]=dummy[k++];
        }
    }
    void mergeSort(vector<pair<int,int>>&v,int l,int r,vector<int>&ans)
    {
        if(l>=r) return ;

        int mid=(l+r)/2;
        mergeSort(v,l,mid,ans);
        mergeSort(v,mid+1,r,ans);
        merge(v,l,mid,r,ans);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();

        vector<int>ans(n,0);
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i],i});
        }
        mergeSort(v,0,n-1,ans);
        return ans;
    }
};