class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<k;i++)
        {
            while(!dq.empty() && nums[dq.back()]<nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);//insert index
        }


        //store the answer
        ans.push_back(nums[dq.front()]);

        for(int i=k;i<n;i++)
        {
            //remove out of window index element from dequeue
            while(!dq.empty() && (i-dq.front()>=k))
            {
                dq.pop_front();
            }

            //insert the element
            while(!dq.empty() && nums[dq.back()]<nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);//insert index


            //store the answer
            ans.push_back(nums[dq.front()]);

        }
        return ans;
    }
};