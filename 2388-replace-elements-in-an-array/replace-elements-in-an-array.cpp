class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int,int>m1,m2;
        for(int i=0;i<nums.size();i++)
        {
            m1[nums[i]]=i+1;
            m2[i+1]=nums[i];
            //1 based indexing
        }

        for(auto x:operations)
        {
            int value=x[0];
            int new_value=x[1];
            int index=m1[value];
            
            m2[index]=new_value;

            m1.erase(value);
            m1[new_value]=index;
        }

        vector<int>ans;
        for(auto x:m2)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};












// class Solution {
// public:
//     vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
//         map<int,int>mp;
//         for(int i=0;i<nums.size();i++)
//         {
//             mp[nums[i]]=i;
//         }
//         //now replace 
//         for(auto &v:operations)
//         {
//             int a=v[0];
//             int b=v[1];

//            int index=mp[a];
//            mp.erase(a);
//            mp[b]=index;
//         }
//         //sort the map
//           // Create a vector of pairs.
//             vector<pair<int, int>> vec;
//             for (auto it = mp.begin(); it != mp.end(); ++it) {
//                 vec.push_back(make_pair(it->second, it->first));  //insert second value first bcz we want sorting based on index
//             }

        
//         sort(vec.begin(),vec.end());
//         //now isnert in answer
//         vector<int>ans;
        
//         for(auto i:vec)
//         {
//             ans.push_back(i.second);
//         }
//         return ans;
//     }
// };