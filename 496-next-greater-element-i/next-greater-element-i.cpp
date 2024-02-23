class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>mp;
        vector<int>ans(nums1.size());
        for(int i=nums2.size()-1;i>=0;i--)
        {
            if(st.empty())
            {
               mp[nums2[i]]=-1;
                st.push(nums2[i]);
            }
            else if(st.top()>nums2[i])
            {
                mp[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
            else //st.top()<=nums2[i]
            {
                while(!st.empty()&&st.top()<=nums2[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                     mp[nums2[i]]=-1;
                    st.push(nums2[i]);
                }
                else
                {
                mp[nums2[i]]=st.top();
                st.push(nums2[i]);
                }
                
            }
        }
        
        
        //now traverse in nums2 and check whose next greater element need
        for(int j=0;j<nums1.size();j++)
        {
              ans[j]=mp[nums1[j]];    
        }
        return ans;
    }
};