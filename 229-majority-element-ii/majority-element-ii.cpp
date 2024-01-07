class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maj1;
        int count1=0;

        int maj2;
        int count2=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==maj1)
            {
                count1++;
            }
            else if(nums[i]==maj2)
            {
                count2++;
            }
            else if(count1==0)
            {
                maj1=nums[i];
                count1=1;
            }
            else if(count2==0)
            {
                maj2=nums[i];
                count2=1;
            }
            else 
            {
                count1--;
                count2--;
            }

        }

        //now verify maj1 and maj2

        int freq1=0,freq2=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==maj1)
            {
                freq1++;
            }
            if(nums[i]==maj2)
            {
                freq2++;
            }
        }

        if(freq1>nums.size()/3)
        ans.push_back(maj1);

        if(freq2>nums.size()/3)
        ans.push_back(maj2);
        return ans;
    }
};