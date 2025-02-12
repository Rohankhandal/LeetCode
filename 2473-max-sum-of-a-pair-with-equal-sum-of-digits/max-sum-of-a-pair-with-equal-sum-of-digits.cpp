class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>v;
        for(auto &num:nums){
            int sum=0;
            int temp=num;
            while(temp)
            {
                int rem=temp%10;
                sum+=rem;
                temp/=10;
            }
            v.push_back({sum,num});
        }

        sort(v.begin(),v.end());
        int maxSum=0;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            if(i+1<n && v[i].first==v[i+1].first )
            {
               sum=v[i].second+v[i+1].second; 
            }
            maxSum=max(maxSum,sum);
        }
        return maxSum==0?-1:maxSum;
    }
};