// class Solution {
// public:
//     bool check(vector<int>& nums) {
//         int n=nums.size();
//         for(int rotate=0;rotate<n;rotate++)
//         {
//             vector<int>temp(n,0);
//             for(int j=0;j<n;j++)
//             {
//                 temp[((rotate+j)%n)]=nums[j];
//             }
//             if(is_sorted(temp.begin(),temp.end())) return true;
//         }
//         return false;
        
//     }
// };


class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) cnt++;
        }

        if(nums[n-1]>nums[0]) cnt++;

        return (cnt<=1);
        
    }
};