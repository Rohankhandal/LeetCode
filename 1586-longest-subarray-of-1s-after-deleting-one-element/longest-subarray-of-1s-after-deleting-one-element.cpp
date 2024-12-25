class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        int i=0,j=0;
        int zero=1;
        while(j<n)
        {
            if(arr[j]==0) zero--;

            while(zero<0 && i<=j)
            {
                if(arr[i]==0) zero++;
                i++;
            }

            ans=max(j-i+1,ans);
            j++;
            
        }
        return ans-1;
    }
};