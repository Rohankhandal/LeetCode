//Using O(1) space and same pattern - "Using numbers as indices"
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool containOne=false;
        //first check whether 1 is present or not in array
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                containOne=true;
            }
            //if we find a element which is <0 and >n then change in 1
            if(nums[i]<=0 || nums[i]>n)
            {
                nums[i]=1;   //bcz range is [1,n] and this are valid index
            }
        }

        if(containOne==false) return 1;
        // Mark whether integers 1 to n are in nums
        // Use index as a hash key and negative sign as a presence detector

        //traverse throught element in array
        for(int i=0;i<n;i++)
        {
            int val=abs(nums[i]);
            int idx=val-1;

            if(nums[idx] < 0) continue;
            nums[idx] *= -1;
        }


        // First positive in nums is smallest missing positive integer
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                return i+1;
        }

        return n + 1;
       
    }
};


// T.C:-O(N)
// S.C:-O(N)
// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         int n=nums.size();
//         vector<bool>mark(n+1,false);
//         for(auto &it:nums)
//         {
//             if(it>=0 && it<=n)
//                 mark[it]=true;
//         }
//         for(int i=1;i<n+1;i++){    //traverse from index 1
//             if(mark[i]==false)
//                 return i;
//         }
//         return n+1;
       
//     }
// };