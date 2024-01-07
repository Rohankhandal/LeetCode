class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] != val){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};


// class Solution {
// public:
//     int removeElement(vector<int>& nums, int val) {
//        int pos;
//        int count=0;
//        int k=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]==val)
//             {
//                 count++;
//             }
//             else
//             {
//                 k++;
//             }
//         }
// while(count--)
// {
//     for(int i=0;i<nums.size();i++)
//         {
//             if(nums[i]==val)
//             {
//                 pos=i;
//                 break;
//             }
//         }
//         for(int i=pos;i<nums.size()-1;i++)
//         {
//             nums[i]=nums[i+1];
//         }

// }
// return k;
        
//     }
// };