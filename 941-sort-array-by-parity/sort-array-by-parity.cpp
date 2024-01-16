class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int sz = nums.size(), left = 0, right = sz-1;
        while(left < right){
            
            while(left < right && nums[left] % 2 == 0){
                left++;
            }
            while(right > left && nums[right] % 2 != 0){
                right--;
            }
            if(left < right){
                swap(nums[left], nums[right]);
            }
        }
        return nums;
    }
};