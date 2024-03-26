class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        set<int>mp;
        for(auto &it:nums)
        {
            mp.insert(it);
        }   
        int temp=*mp.begin();
        int num=temp;
        int count=1;
        int ans=INT_MIN;
        for(auto &val:mp)
        {
            if(val==temp) continue;
            if(val==num+1)
            {
                count++;
            }
            else{
                 ans=max(ans,count);
                count=1;
            }
            num=val;
        }
       ans=max(ans,count);  //if else condition is not excuted
        return  ans;
    }
};