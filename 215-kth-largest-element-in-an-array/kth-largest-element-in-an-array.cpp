//Approach-3 (Using QuickSelect Algorithm
//Time complexity: O(n) on average, O(n2) in the worst case


class Solution {
public:
int partition_algo(vector<int>&nums,int L, int R)
{
    int P=nums[L];
    // int i=L;  //this work but if nums=[1] then not work
    int  i=L+1;
    int j=R;
    while(i<=j)
    {
        if(nums[i]<P && nums[j]>P)
        {
            swap(nums[i],nums[j]);
        }
        if(nums[i]>=P)
        {
            i++;
        }
        if(nums[j]<=P)
        {
            j--;
        }
    
    }
    swap(nums[L],nums[j]);
    return j;  //P is at jth index
    }
    int findKthLargest(vector<int>& nums, int k) {
       int n=nums.size();
       int L=0;
       int R=n-1;
       int pivot_idx=0;

       while(true)
       {
           pivot_idx=partition_algo(nums,L,R);
           if(pivot_idx==k-1)
           {
               break;
           }
           else if(pivot_idx>k-1)
           {
               R=pivot_idx-1;
           }
           else
           {
               L=pivot_idx+1;
           }
       }
       return nums[pivot_idx];
    }
};