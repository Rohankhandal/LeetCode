// class Solution {
// public:
// //    Time complexity:
// //       O(N)

//     // Space complexity:
//     // O(1)
//     void rotate(vector<int>& nums, int k) {
        
//      k=k%nums.size();   //Imp part
//         reverse(nums.begin(),nums.begin()+(nums.size()-k));

//         reverse(nums.begin()+(nums.size()-k),nums.end());
    
//         reverse(nums.begin(),nums.end());
//     }
// };




class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle cases where k > n
        if (k == 0) return; // No rotation needed

        // Use std::rotate to perform the rotation
        std::rotate(nums.begin(), nums.end() - k, nums.end());
    }
};
