class Solution
{
    public:
        int singleNonDuplicate(vector<int> &arr)
        {
            int n = arr.size();
            int l = 1;
            int r = arr.size() - 2;
            int ans=-1;
            if (arr.size() == 1)
            {
                return arr[0];
            }
            if (arr[0] != arr[1])
            {
                return arr[0];
            }
            if (arr[n - 1] != arr[n - 2])
            {
                return arr[n - 1];
            }

            while (l <= r)
            {
                int mid = l + (r - l) / 2;

                if(mid%2==0)
                {
                    if( arr[mid]==arr[mid-1])
                    {
                        r=mid-2;
                        ans=arr[r];
                    }
                    else
                    {
                        ans=arr[mid];
                        l=mid+1;
                    }
                }
                else
                {
                    if(arr[mid]==arr[mid-1])
                    {
                        l=mid+1;
                    }
                    else{
                        ans=arr[mid-1];
                        r=mid-2;
                    }
                }
            }
            return ans;
        }
};