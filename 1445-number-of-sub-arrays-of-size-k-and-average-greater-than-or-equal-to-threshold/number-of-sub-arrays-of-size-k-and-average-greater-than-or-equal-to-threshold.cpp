class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans=0;
        int sum=0;
        int n=arr.size();
        //first process k window
        for(int i=0;i<k;i++)
        {
            sum+=arr[i];
        }
        if(sum/k>=threshold) ans++;

        for(int i=k;i<n;i++)
        {
           //remove first element of last window
           sum-=arr[i-k];
           sum+=arr[i];
           if(sum/k>=threshold) ans++;
        }

        return ans;

    }
};