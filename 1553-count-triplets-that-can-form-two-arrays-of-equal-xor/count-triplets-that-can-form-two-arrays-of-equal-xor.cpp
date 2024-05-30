class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count=0;
        int n=arr.size();
        for(int i=0;i<n-1;i++)
        {
            int a=0;
            for(int j=i;j<n-1;j++)
            {
                a^=arr[j];
                int b=0;
                for(int k=j+1;k<n;k++)
                {
                    b^=arr[k];
                    if(a==b)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};