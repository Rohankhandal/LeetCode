class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>freq;
        long long totalPair=1LL*n*(n-1)/2;
         long long goodPair=0;
        for(int i=0;i<n;i++)
        {
            if(freq.find(i-nums[i])!=freq.end()) goodPair+=freq[i-nums[i]];
            freq[i-nums[i]]++;
        }
        // cout<<goodPair<<endl;
        return totalPair-goodPair;
    }
};