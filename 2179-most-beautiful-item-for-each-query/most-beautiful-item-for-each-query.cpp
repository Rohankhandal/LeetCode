class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans;
        unordered_map<int, int> mp;

        // Store the maximum beauty for each price
        for (auto& item : items) {
            int price = item[0];
            int beauty = item[1];
            if (mp.find(price) != mp.end()) {
                mp[price] = max(mp[price], beauty);
            } else {
                mp[price] = beauty;
            }
        }

        // Convert map to a sorted vector of price-beauty pairs
        vector<pair<int, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end());

        // Build prefix max array for beauties
        int sz = v.size();
        for (int i = 1; i < sz; i++) {
            v[i].second = max(v[i].second, v[i - 1].second);
        }

        // Process each query
        for (int q : queries) {
            int l = 0, r = sz - 1;
            int ansIdx = -1;

            // Binary search to find the largest price <= query
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (v[mid].first <= q) {
                    ansIdx = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            // If a valid price was found, use the max beauty; otherwise, 0
            if (ansIdx == -1) ans.push_back(0);
            else ans.push_back(v[ansIdx].second);
        }

        return ans;
    }
};
