class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int cur=0;
        int i=0,j=0;
        int n=nums.size();
        long long res=0;
        unordered_map<int,int>mp;
        while(i<n){
            while(i<j && cur>=k){
                if(mp[nums[i]]>=2) cur-=(mp[nums[i]]-1);
                mp[nums[i]]--;
                i++;
                res+=n-j+1;
            }
            while(j<n && cur<k){
                mp[nums[j]]++;
                if(mp[nums[j]]>=2) cur+=mp[nums[j]]-1;
                j++;
            }
            if(j==n && cur<k) break;
        }
        return res;
    }
};