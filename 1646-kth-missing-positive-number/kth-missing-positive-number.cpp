class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>num(3002,0);
        for(int i=0;i<arr.size();i++)
        {
            num[arr[i]]=1;
        }
        //traverse k empty values in num
        for(int i=1;i<3002;i++)
        {
            if(num[i]==0)
            {
                k--;
                if(k==0) return i;
            }
        }
        return -1;
    }
};