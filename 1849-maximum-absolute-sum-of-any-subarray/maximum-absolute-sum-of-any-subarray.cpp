class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int count = 0;
        for (auto& it : nums) {
            count += it;
            maxi = max(maxi, count);
            if (count < 0) {
                count = 0;
            }
        }
        count=0;
         for (auto& it : nums) {
            count += it;
            mini = min(mini, count);
            if (count > 0) {
                count = 0;
            }
        }
        
        return max(maxi,abs(mini));
    }
};