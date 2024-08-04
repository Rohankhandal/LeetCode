//Approach-1 (Using complete sorting)
//T.C : O(nlogn)
//S.C : O(1)
// class Solution {
// public:
//     int minDifference(vector<int>& nums) {
//         sort(begin(nums), end(nums));
//         int n = nums.size();
//         if(n <= 4) {
//             return 0;
//         }
//         int result = INT_MAX;
//         result = min(result, nums[n-4] - nums[0]);
//         result = min(result, nums[n-1] - nums[3]);
//         result = min(result, nums[n-3] - nums[1]);
//         result = min(result, nums[n-2] - nums[2]);

//         return result;
//     }
// };


//Approach-2 (Using Partial Sorting)
//T.C : O(n)
//S.C : O(1)
// class Solution {
// public:
//     int minDifference(vector<int>& nums) {
//         int n = nums.size();
//         int result = INT_MAX;
//         if(n <= 4)
//             return 0;

//         partial_sort(begin(nums), begin(nums) + 4, end(nums));

//         nth_element(begin(nums) + 4, begin(nums) + (n - 4), end(nums));
       
//         sort(begin(nums) + (n - 4), end(nums)); //4th largest element will be correct

//         result = min(result, nums[n-4] - nums[0]);
//         result = min(result, nums[n-1] - nums[3]);
//         result = min(result, nums[n-3] - nums[1]);
//         result = min(result, nums[n-2] - nums[2]);

//         return result;
//     }
// };



class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
       if(n <= 4) {
            return 0;
        }
        int ans=INT_MAX;
        sort(nums.begin(),nums.end());

        // change starting 3 element 
        int op1=nums[n-1]-nums[3];

         // change last 3 element 
        int op2=nums[n-4]-nums[0];

         // change starting 3 element 
        int op3=nums[n-2]-nums[2];

         // change starting 3 element 
        int op4=nums[n-3]-nums[1];

        return min({op1,op2,op3,op4});

    }
};




