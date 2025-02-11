class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        deque<int>dq;
        for(int i=0;i<k;i++)
        {
            //remove small element
            while(!dq.empty() && nums[dq.back()]<nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);

        for(int i=k;i<n;i++)
        {
            //remove out of window index
            while(!dq.empty() && (i-dq.front())>=k) dq.pop_front();

            //remove small element
            while(!dq.empty() && nums[dq.back()]<nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};