class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int distinctEle=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        unordered_map<int,int>temp;
        for(auto &it:nums)
        {
            mp[it]++;
        }
        distinctEle=mp.size();
        cout<<distinctEle<<endl;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=i;j<n;j++)
            {
                if(temp.count(nums[j])==0)
                {
                    count++;
                }
                if(count==distinctEle)
                {
                    ans++;
                }
                temp[nums[j]]++;

            }
            temp.clear();
        }
        return ans;
    }
};