//first take mutiplication of all number except zero and if count of negative number is odd then 
//divide the result by greatest value of negative number

//Also, take care of edge case e.g:-[-1,0,0]

//T.C:-O(N)
//BEST

// class Solution {
// public:
//     long long maxStrength(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1) return nums[0];

//         int negCount=0;
//         int larNegEle=INT_MIN;
//         int larEle=INT_MIN;
//         long long product=1;
//         for(int i=0;i<n;i++)
//         {
//             //update -ve count and lareNegEle, larEle;
//             if(nums[i]<0)
//             {
//                 negCount++;
//                 larNegEle=max(larNegEle,nums[i]);
//             }
//             larEle=max(larEle,nums[i]);


//             //update product if not 0
//             if(nums[i]) product*=nums[i];
//         }

//         //handle 2nd corner case, one -ve, some 0's, no +ve
//         if(larEle==0 and negCount<=1) return 0;
//         //handle odd -ve case

//         if(negCount%2) return product/larNegEle;


//         return product;

//     }
// };



//BRUTE FORCE
class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        vector<long long>pos,neg,zero;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0) neg.push_back(-nums[i]);
            else if(nums[i]>0) pos.push_back(nums[i]);
            else zero.push_back(nums[i]);
        }


        sort(neg.begin(),neg.end(),greater<long long>());

        
        //take multiply of all positive number
        if(pos.size()>0)
        {
            long long product=1;
            for(int i=0;i<pos.size();i++)
            {
                product=product*pos[i];
            }

            if(neg.size()>1)
            {
                int sz=neg.size();
                if(sz%2) sz--;

                for(int i=0;i<sz;i++)
                {
                    product=product*neg[i];
                }
            }
            return product;
        }
        else{
            if(neg.size()>1)
            {
                long long ans=1,sz=neg.size();
                if(sz%2) sz--;

                for(long long i=0;i<sz;i++)
                {
                    ans=ans*neg[i];
                }

                return ans;
            }
            else
            {
                if(neg.size()==1 && zero.size()) return 0;
                else if(zero.size()) return 0;
                else return -neg[0];
            }
        }
        return 0;


    }
};