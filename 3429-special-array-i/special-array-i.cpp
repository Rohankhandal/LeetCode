class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool flag=true;
        int n=nums.size();
        if(n==1) return true;
        for(int i=1;i<n;i++){
            if((nums[i]%2==nums[i-1]%2) )
            {
                flag=false;break;
            }
        }
        return flag;
    }
};