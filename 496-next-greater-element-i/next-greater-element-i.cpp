class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>temp;
        vector<int>ans;
        int n1=nums1.size();
        int n2=nums2.size();

        st.push(nums2[n2-1]);
        temp.push_back(-1);

        for(int i=n2-2;i>=0;i--)
        {
            if(st.empty())
            {
                temp.push_back(-1);
                st.push(nums2[i]);
            }
            else
            {
                while(!st.empty() && st.top()<nums2[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    temp.push_back(-1);
                     
                }
                else
                {
                    temp.push_back(st.top());
                }
                st.push(nums2[i]);
            }
        }
        reverse(temp.begin(),temp.end());
        unordered_map<int,int>mp;
        for(int i=0;i<n2;i++)
        {
            mp[nums2[i]]=i;
        }
        for(int i=0;i<n1;i++)
        {
            ans.push_back(temp[mp[nums1[i]]]);
        }
        return ans;
    }
};