class Solution {
public:
    int space(vector<int>&nums)   //Longest Increasing Subsequence space optimize code
    {
        int n=nums.size();
        vector<int>first(n+1,0);
        vector<int>next(n+1,0);
        //bcz prev =-1 , so then index is invalid , so we replace prev => prev+1;

        for(int curr=n-1;curr>=0;curr-- )
        {
            for(int prev=curr-1;prev>=-1;prev--)
            {
                int include=0;
                if(prev==-1  || nums[curr]>nums[prev]){
                    include=1+next[curr+1];
                }
                int exclude=0+next[prev+1];

                first[prev+1]=max(include,exclude);
               
            }
            next=first;
        }
        return next[-1+1];
    }
    int binarySearch(vector<int>&nums)
    {
        if(nums.size()==0) return 0;
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                //overwrite 
                //find the index of just greater element
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();

    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        auto myCmp=[](vector<int>&v1,vector<int>&v2)
        {
            if(v1[0]==v2[0])
            {
                return v1[1]>v2[1];
            }
            else
                return v1[0]<v2[0];
        };
        sort(envelopes.begin(),envelopes.end(),myCmp);
        vector<int>height;
        for(auto &it:envelopes)
        {
            height.push_back(it[1]);
        }
        // return space(height);

        return binarySearch(height);
    }
};