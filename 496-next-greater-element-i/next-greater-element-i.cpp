class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater; // Maps elements of nums2 to their next greater element
        stack<int> st;

        // Compute the next greater element for each number in nums2
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // For remaining elements in the stack, there is no next greater element
        while (!st.empty()) {
            nextGreater[st.top()] = -1;
            st.pop();
        }

        // Map the results for nums1 using the precomputed nextGreater map
        vector<int> ans(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            ans[i] = nextGreater[nums1[i]];
        }

        return ans;
    }
};
