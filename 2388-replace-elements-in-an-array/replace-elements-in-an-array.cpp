class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=i;
        }
        //now replace 
        for(auto &v:operations)
        {
            int a=v[0];
            int b=v[1];

           int index=mp[a];
           mp.erase(a);
           mp[b]=index;
        }
        //sort the map
          // Create a vector of pairs.
            vector<pair<int, int>> vec;
            for (auto it = mp.begin(); it != mp.end(); ++it) {
                vec.push_back(make_pair(it->second, it->first));  //insert second value first bcz we want sorting based on index
            }

        
        sort(vec.begin(),vec.end());
        //now isnert in answer
        vector<int>ans;
        
        for(auto i:vec)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};