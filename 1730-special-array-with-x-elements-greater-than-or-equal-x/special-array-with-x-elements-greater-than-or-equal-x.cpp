class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();  //answer not greater than n (Observation)
        sort(nums.begin(),nums.end());
        int l=0,r=n;
        while(l<=r)
        {
            int mid=(l+r)/2;
            int idx=lower_bound(nums.begin(),nums.end(),mid)-nums.begin();
            int diff=n-idx;
            if(mid==diff) return mid;
            else if(mid>diff) r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
};