class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int val=1;
        int cnt=0;
        int i=0;
        while(i<n)
        {
            if(arr[i]!=val)
            {
                val++;
                cnt++;
            }
            else
            {
                val++;
                i++;
            }
            if(cnt==k) return val-1;
        }
        return val-1+(k-cnt);
    }
};