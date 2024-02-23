class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans;
        stack<int>st;
        int n=nums.size();
        //for circular array ,we add array nums in exist array nums
        // e.g nums=[1,2,1] after add array itself
        // nums=[1,2,1,1,2,1]
        //we thing virtual of cirular array
        for(int i=2*n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums[i%n]) //IMP
            {
                st.pop();
            }
            //if index i is in range of 0 to n
            if(i<n)
            {
                int temp=st.empty()?-1:st.top();
                ans.push_back(temp);
            }
            st.push(nums[i%n]);

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};