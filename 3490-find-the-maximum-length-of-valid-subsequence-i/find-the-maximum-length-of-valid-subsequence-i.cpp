class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        //we have to count maximum from (total no. of even elements or total no. of odd element, or pattern of even-odd, or pattern of odd-even)
        int n=nums.size();

        int evenCnt=0;
        for(int i=0;i<n;i++)
        {
            if(!(nums[i]&1)) evenCnt++;
        }

        int oddCnt=n-evenCnt;

        //now find even-odd pairs
        int flag=0;
        int evenToOdd=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0 && flag==0)
            {
                evenToOdd++;
                flag=1;
            }

            if(nums[i]%2==1 && flag==1)
            {
                evenToOdd++;
                flag=0;
            }
        }

        //now find odd-Even
        flag=1;
        int oddToEven=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==1 && flag==1)
            {
                oddToEven++;
                flag=0;
            }
            if(nums[i]%2==0 && flag==0)
            {
                oddToEven++;
                flag=1;
            }
        }

        return max({evenCnt,oddCnt,oddToEven,evenToOdd});
    }
};