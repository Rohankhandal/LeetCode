class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        stack<int>st;
        int n=nums2.size();
        for(int i=n-1;i>=0;i--)
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
            else   //st.top()<nums2[i]
            {
                while(!st.empty() && st.top()<=nums2[i])
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
        //for store ans 
        for(auto &it:mp)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }
        vector<int>ans(nums1.size());
        for(int i=0;i<nums1.size();i++)
        {
            ans[i]=mp[nums1[i]];
        }
        return ans;
    }
};