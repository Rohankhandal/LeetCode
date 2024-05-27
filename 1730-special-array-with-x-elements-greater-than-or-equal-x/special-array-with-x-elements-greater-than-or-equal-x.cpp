class Solution {
public:
    int specialArray(vector<int>& nums) {
        int maxEle=*max_element(nums.begin(),nums.end());
        for(int i=0;i<=maxEle;i++)
        {
            int cnt=0;
            for(int j=0;j<nums.size();j++)
            {
                
                if(nums[j]>=i) cnt++;
            }
            if(cnt==i) return i;
        }
        return -1;
    }
};