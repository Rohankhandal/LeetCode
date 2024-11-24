class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>temp(nums2.size(),-1);
        stack<int>st;
        st.push(nums2[nums2.size()-1]);
        for(int i=nums2.size()-2;i>=0;i--)
        {
            if(nums2[i]<st.top())
            {
                temp[i]=st.top();
            }
            else
            {
                while(!st.empty() && nums2[i]>=st.top())
                {
                    st.pop();
                }
                if(!st.empty()) 
                {
                    temp[i]=st.top();
                }
            }

            st.push(nums2[i]);

        }
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++)
        {
            mp[nums2[i]]=i;
        }

        vector<int>ans(nums1.size(),0);
        for(int i=0;i<nums1.size();i++)
        {
            ans[i]=temp[mp[nums1[i]]];
        }
        return ans;
    }
};