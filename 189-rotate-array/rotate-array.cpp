class Solution {
public:
//    Time complexity:
//       O(N)

    // Space complexity:
    // O(1)
    void rotate(vector<int>& nums, int k) {
        
     k=k%nums.size();   //Imp part
        reverse(nums.begin(),nums.begin()+(nums.size()-k));

        reverse(nums.begin()+(nums.size()-k),nums.end());
    
        reverse(nums.begin(),nums.end());
    }
};