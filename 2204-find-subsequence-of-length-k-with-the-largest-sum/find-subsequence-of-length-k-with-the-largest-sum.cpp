class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> v;
        for(int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});  // store value and index
        }

        sort(v.begin(), v.end());  // sort by value
        vector<pair<int, int>> top;
        int n = nums.size();

        for(int i = n - 1; i >= n - k; i--) {
            top.push_back(v[i]);  // take top k largest
        }

        sort(top.begin(), top.end(), [](auto &a, auto &b) {
            return a.second < b.second;  // sort by original index
        });

        vector<int> ans;
        for(auto &x : top) {
            ans.push_back(x.first);  // collect values
        }

        return ans;
    }
};
