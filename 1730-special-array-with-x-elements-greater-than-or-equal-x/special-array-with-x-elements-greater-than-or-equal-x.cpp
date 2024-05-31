class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();  //answer not greater than n (Observation)
        sort(nums.begin(),nums.end());
        for(int i=0;i<=n;i++)
        {
           
            int idx=lower_bound(nums.begin(),nums.end(),i)-nums.begin();
            // cout<<idx<<endl;

            if(i==(n-idx)) return i;
        }
        return -1;
    }
};