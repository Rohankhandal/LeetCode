class Solution {
public:
    void merge(vector<pair<int, int>>& v, int l, int mid, int r, vector<int>& ans) {
        int n1 = mid - l + 1;
        int n2 = r - mid;

        vector<pair<int, int>> dummy(n1 + n2);
        int i = l, j = mid + 1, k = 0;

        while (i <= mid && j <= r) {
            if (v[i].first <= v[j].first) {
                // No element on the right is smaller than v[i]
                dummy[k++] = v[j++];
            } else {
                // All elements from v[j] to v[r] are smaller than v[i]
                ans[v[i].second] += (r - j + 1);
                dummy[k++] = v[i++];
            }
        }

        while (i <= mid) dummy[k++] = v[i++];
        while (j <= r) dummy[k++] = v[j++];

        for (int p = 0; p < k; ++p) {
            v[l + p] = dummy[p];
        }
    }

    void mergeSort(vector<pair<int, int>>& v, int l, int r, vector<int>& ans) {
        if (l >= r) return;

        int mid = (l + r) / 2;
        mergeSort(v, l, mid, ans);
        mergeSort(v, mid + 1, r, ans);
        merge(v, l, mid, r, ans);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; ++i) {
            v.push_back({nums[i], i});
        }

        mergeSort(v, 0, n - 1, ans);
        return ans;
    }
};
