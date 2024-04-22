//first take mutiplication of all number except zero and if count of negative number is odd then 
//divide the result by greatest value of negative number

//Also, take care of edge case e.g:-[-1,0,0]
class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        int negCount=0;
        int larNegEle=INT_MIN;
        int larEle=INT_MIN;
        long long product=1;
        for(int i=0;i<n;i++)
        {
            //update -ve count and lareNegEle, larEle;
            if(nums[i]<0)
            {
                negCount++;
                larNegEle=max(larNegEle,nums[i]);
            }
            larEle=max(larEle,nums[i]);


            //update product if not 0
            if(nums[i]) product*=nums[i];
        }

        //handle 2nd corner case, one -ve, some 0's, no +ve
        if(larEle==0 and negCount<=1) return 0;
        //handle odd -ve case

        if(negCount%2) return product/larNegEle;


        return product;

    }
};