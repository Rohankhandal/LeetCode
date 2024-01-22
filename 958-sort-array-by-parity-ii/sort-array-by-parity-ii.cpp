class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();

        vector<int>oddEle(n/2);
        vector<int>evenEle(n/2);
        int oddIndex=0;
        int evenIndex=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                evenEle[evenIndex]=nums[i];
                evenIndex++;
            }
            else
            {
                oddEle[oddIndex]=nums[i];
                oddIndex++;
            }
        }
        // Now sorting according to condition
        evenIndex--;
        oddIndex--;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                nums[i]=evenEle[evenIndex];
                evenIndex--;
            }
            else
            {
                nums[i]=oddEle[oddIndex];
                oddIndex--;
            }
        }
        return nums;

    }
};