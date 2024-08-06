class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //find the first deceasing element
        int n=nums.size();

        int index=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }

        if(index==-1)
        {
            reverse(nums.begin(),nums.end());
            return ;
        }

        //find the next greater elemnt to index element

        // Step 2: Find the next greater element
         //         and swap it with arr[ind]:

    for (int i = n - 1; i > index; i--) {
        if (nums[i] > nums[index]) {
            swap(nums[i], nums[index]);
            break;
        }
    }
        
      
        reverse(nums.begin()+index+1,nums.end());

    }
};