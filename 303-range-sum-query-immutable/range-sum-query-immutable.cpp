class NumArray {
public:
vector<int>arr;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        for(auto &it:nums)
         arr.emplace_back(it);
    }
    
    int sumRange(int left, int right) {
        long long sum=0;
        for(int i=left;i<=right;i++)
        {
            sum+=arr[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */