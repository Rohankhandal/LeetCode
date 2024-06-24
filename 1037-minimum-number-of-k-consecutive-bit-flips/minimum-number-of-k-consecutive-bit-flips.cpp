class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int flip=0;
        int ans=0;
        vector<bool>flipArray(n,false);
        for(int i=0;i<n;i++)
        {

            if(i>=k && flipArray[i-k])
            {
                flip--;
            }
            if((flip+nums[i])%2==0)
            {
                if(i+k>n) return -1;
                
                flipArray[i]=true;
                flip++;
                ans++;
            }
            nums[i]=(flip+nums[i])%2;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) return -1;
        }
        return ans;
    }
};