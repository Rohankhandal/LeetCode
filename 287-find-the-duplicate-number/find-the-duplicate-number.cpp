//T.C : O(n) Using "Hare & tortoise technique"
//S.C : O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        slow = nums[slow];
        fast = nums[nums[fast]];
        
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        slow = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};

// https://www.youtube.com/watch?v=qNx2nKBdvwU&ab_channel=AryanMittal
//Binary Search [Not intutional to think to apply Binary Search]
// T.C:-O(nlogn)
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int len=nums.size();
//         int low=1,high=len-1,ans=0;
//         while(low<=high)
//         {
//             int mid=(low+high)/2;
//             int cnt=0;
//             for(int i=0;i<len;i++)   //count how many numbers are less or 
//             //or equal to the mid element in array
//             {
//                 if(nums[i]<=mid)
//                 {
//                     cnt++;
//                 }
//             }

//             if(cnt<=mid) low=mid+1;
//             else
//             {
//                 ans=mid;
//                 high=mid-1;
//             }

//         }
//         return ans;
//     }
// };


//Bit Manipulation:-
// nums=>[1,3,3,2,4];
// original=>[1,2,3,4];
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
        
//     }
// };










// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             int index=abs(nums[i]);
//             if(nums[index]<0)
//                 return index;
            
//             nums[index]=-nums[index];
//         }
//         return -1;
//     }
// };