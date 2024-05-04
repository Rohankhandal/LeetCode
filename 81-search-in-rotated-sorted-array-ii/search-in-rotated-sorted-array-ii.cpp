class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n=arr.size();
        int l=0,r=n-1;
        while(l<=r)
        {
             while(l<r && arr[l]==arr[l+1]) l++;
            while(l<r && arr[r]==arr[r-1]) r--;
            int mid=(l+r)/2;
            if(arr[mid]==target) return true;
            else  if(arr[l]<=arr[mid]) //left part is sorted
            {
                if(target>=arr[l] && target<=arr[mid])
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            else
            {
                if(target>arr[mid] && target<=arr[r])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
        }
        return false;
    }
};