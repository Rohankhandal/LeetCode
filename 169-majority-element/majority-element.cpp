class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int val=NULL;
        int cnt=0;

        for(int i=0;i<n;i++)
        {
            if(cnt==0)
            {
                val=nums[i];
                cnt++;
            }
            else if(val==nums[i])
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }

        return val;
    }
};