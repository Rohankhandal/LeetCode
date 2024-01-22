//Index is not ask in question, so
//sort the array 
// then use two pointer approach
//one variable is static e.g=>k=0 to k=n-3
//second variable is started from i=k+1
//third variable is j=n-1
//for second and third variable two pointer approach will work
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closestSum=1e5;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        for(int k=0;k<=n-3;k++)
        {
            int i=k+1;
            int j=n-1;
            int sum=0;
            while(i<j)
            {
                sum=nums[k]+nums[i]+nums[j];
                if(abs(target-sum)<abs(target-closestSum))
                {
                    closestSum=sum;
                }

                if(sum<target)
                {
                    i++;
                }
                else
                {
                    j--;
                }

            }
        }
        return closestSum;   //e.g nums=[0,0,0] then output 1000
  
    }
};