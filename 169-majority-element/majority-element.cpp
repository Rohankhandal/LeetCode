class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj;           //Boyer-Moore Vooting Algorithm  S.C O(1)
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==maj)
            {
                count++;
            }
            else if(count==0)
            {
                maj=nums[i];
                count=1;
            }
            else
            {
                count--;
            }
        }
        return  maj;   //if don't do verify that maj is really a majority element bcz in question given that there is always exist a maj. element.
        
    }
};


//Using map S.c O(n);
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int,int>mp;
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             mp[nums[i]]++;
//         }
//         //chech majority
//         for(auto &it:mp)
//         {
//             int freq=it.second;
//             if(freq>n/2)
//             {
//                 return it.first;
//             }
//         }

//         return -1;
        
//     }
// };