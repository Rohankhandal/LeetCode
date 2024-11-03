class Solution {
public:
    vector<int> leftNextSmaller(vector<int>& arr) {
        stack<int> st;
        int n=arr.size();
        vector<int> temp;
        temp.push_back(-1);
        st.push(0); // insert index
        for (int i = 1; i < n; i++) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                temp.push_back(-1);
                st.push(i);
            } else {
                temp.push_back(st.top());
                st.push(i);
            }
        }
        return temp;
    }
    vector<int> rightNextSmaller(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        vector<int> temp;
        temp.push_back(n);
        st.push(n-1); // insert index
        for (int i = n-2; i >=0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                temp.push_back(n);
                st.push(i);
            } else {
                temp.push_back(st.top());
                st.push(i);
            }
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> LNS = leftNextSmaller(heights);
        vector<int> RNS = rightNextSmaller(heights);

        vector<int> width(n, 0);
        for(auto &it:LNS)
        {
            cout<<it<<" ";
        }
        cout<<endl;

        for(auto &it:RNS)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int L = RNS[i] - LNS[i] - 1;
            ans = max(ans, heights[i] * L);
        }
        return ans;
    }
};