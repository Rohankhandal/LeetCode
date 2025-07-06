class FindSumPairs {
public:
    unordered_map<int,int>mp1;
    unordered_map<int,int>mp2;
    vector<int>nums;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) { //
        for(auto &it:nums1)
        {
            mp1[it]++;
        }
        for(auto &it:nums2)
        {
            mp2[it]++;
        }
        nums=nums2;
    }
    
    void add(int index, int val) {
        mp2[nums[index]]--;
        if(mp2[nums[index]]==0) mp2.erase(nums[index]);
        nums[index]+=val;
        mp2[nums[index]]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(auto &it:mp2)
        {
            int req=tot-it.first;
            if(mp1[req]>0)
            {
                ans+=mp1[req]*it.second;
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */