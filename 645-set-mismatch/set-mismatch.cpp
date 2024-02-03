// Approach 1 - Brute Force
// Approach 2 - Vector
// Approach 3 - Set + sum
// Approach 4 - Maps
// Approach 5 - XOR Operation
// https://leetcode.com/problems/set-mismatch/solutions/4606092/beats-99-08-c-java-python-javascript-5-approaches-explained/?envType=daily-question&envId=2024-01-22

// Aproach-2 (VECTOR)
// Time complexity:
// O(n)

// Space complexity:
// O(n)
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n =nums.size();
        vector<int>v(n+1,0);
        int missing=0,duplicate =0;
        for(int i =0;i<n;i++){
            v[nums[i]]++;
        }
        for(int i =1;i<v.size();i++){
            if(v[i]==2)duplicate = i;
            if(v[i]==0)missing = i;
        }
        return {duplicate,missing};
    }
}; 




// T.C:-O(N)  and S.c:O(1)
// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         vector<int>ans;
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             int index=abs(nums[i])-1;
//             if(nums[index]<0)
//             {
//                 ans.push_back(abs(nums[i]));
//                 // ans.push_back(i+1);
//                 // break;
//                 continue;
//             }
//             nums[index]=-nums[index];
//         }
//         for(int i=0;i<n;i++)
//         {
//             if(nums[i]>0)
//             {
//                 ans.push_back(i+1);
//                 break;
//             }
//         }
//         return ans;
//     }
// };