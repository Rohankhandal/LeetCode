//Approach-1
/*
    Simply maintain a unordered_map. 
    Find the element having frequency 1
    Space Complexity = O(n)
    Time Complexity = O(n)
*/

//Approach-2
/*
    Sort + Smart Traversal
    Time - O(nlogn)
    Space - No extra space
*/
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         for(int i=1;i<n;i+=3)
//         {
//             if(nums[i]!=nums[i-1]) return nums[i-1];
//         }
//         //last element is answer,if answer is not found in above loop
//         return nums[n-1];

        
//     }
// };

//Approach - 3 (Time Complexity : O(32*n))
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
        
//         int result = 0;
        
//         for(int i = 0; i<32; i++) {
            
//             int temp = (1 << i);
            
//             int countOne  = 0;
//             int countZero = 0;
            
//             for(int &num : nums) {
                
//                 if((num&temp) == 0) {
//                     countZero++;
//                 } else {
//                     countOne++;
//                 }
                
//             }
            
//             if(countOne % 3 == 1) {
//                 result = (result | temp);
//             }
            
//         }
        
//         return result;
        
//     }
// };


// Approach 4:-concept of buckets
// T.C:-O(N)
// S.c:-O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ones=0,two=0;
        for(int i=0;i<n;i++)
        {
            ones=(ones^nums[i]) & ~two;
            two=(two^nums[i]) & ~ones;
        }

        return ones;

        
    }
};