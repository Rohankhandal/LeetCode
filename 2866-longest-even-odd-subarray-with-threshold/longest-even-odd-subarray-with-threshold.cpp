class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int thresold) {
        int ans=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0 and nums[i]<=thresold){
                i+=1;
                int count=1;
                while(i<nums.size()){
                    if((nums[i-1]%2)==(nums[i]%2) or nums[i]>thresold){
                        break;
                    }
                    count+=1;
                    i+=1;
                }
                i-=1;
                ans=max(ans,count);
            }
        }
        return ans;
    }
};
//Brute Force
// class Solution {
// public:
//     int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        
//         int ans=INT_MIN;
//         for(int i=0;i<nums.size();i++)
//         {
//             int count=0;
//            if(nums[i]%2==0 && nums[i]<=threshold)
//            {
//                count=1; //if count i as a one number;
//                for(int j=i+1;j<nums.size();j++)
//                {
//                    if(nums[j]>threshold || nums[j]%2==nums[j-1]%2) break;  //IMP OR Condition
//                    count++;
//                }
//            }
//            ans=max(ans,count);

//         }
//         return ans;
//     }
// };