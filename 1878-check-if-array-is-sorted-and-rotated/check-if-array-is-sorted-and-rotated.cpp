//count where increasing order is break including last one number
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>nums[i]) cnt++;
        }

        if(nums[n-1]>nums[0]) cnt++;

        return (cnt<=1);  //including case where all elements are same in array.
    }
};