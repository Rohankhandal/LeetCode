class Solution {
public:
bool isPossible(vector<int>&arr,int capacity,int days)
{
    int sum=0;
    int totalDays=1;  //first day
    for(int i=0;i<arr.size();i++)
    {
        if(sum+arr[i]<=capacity)
        {
            sum+=arr[i];
        }
        else
        {
            sum=arr[i];
            totalDays++; //move to next day
        }
    }
    return totalDays<=days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin() , weights.end());
        // int l=1;  don't start from 1 e.g. 1,2,3,1,1 bcz their no capacity which hold 
        //max value from array if we take less than capacity from max value of element
        int r=accumulate(weights.begin() , weights.end() , 0);
        int ans=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(isPossible(weights,mid,days))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};