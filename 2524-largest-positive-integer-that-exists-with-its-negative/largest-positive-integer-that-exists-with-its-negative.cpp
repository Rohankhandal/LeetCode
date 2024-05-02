class Solution {
public:
    int findMaxK(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int l=0,r=n-1;
        while(l<r)
        {
            if(arr[r]<0) return -1;
            if(arr[l]>0) return -1;
            if(arr[l]<0 && abs(arr[l])==arr[r]) return arr[r];
            else if(abs(arr[l])<arr[r]) r--;
            else l++;
        }
        return -1;
    }
};