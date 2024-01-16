// class Solution {
// public:
//     vector<int> sortArrayByParity(vector<int>& nums) {
//         int sz = nums.size(), left = 0, right = sz-1;
//         while(left < right){
            
//             while(left < right && nums[left] % 2 == 0){
//                 left++;
//             }
//             while(right > left && nums[right] % 2 != 0){
//                 right--;
//             }
//             if(left < right){
//                 swap(nums[left], nums[right]);
//             }
//         }
//         return nums;
//     }
// };


// Using comparator Function
class Solution {
public:
    static bool comparator(int &a  , int & b){
      return a%2 < b%2 ;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size(); 
        if(n==1) return nums;
        sort(nums.begin() , nums.end() , comparator);
        return nums;
    }

};