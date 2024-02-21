class Solution {
public:
    bool possibleRange(vector<int>& houses, vector<int>& heaters, int mid) {
        int i = 0;
        int j = 0;
        int len1 = houses.size();
        int len2 = heaters.size();
        while (i < len1 && j < len2) {
            if (abs(houses[i] - heaters[j]) <= mid) {  //check whether given range(mid) is appilcable for all houses
                i++;
            } else if (houses[i] > heaters[j] && j != len2 - 1) {
                j++;
            } else
                return 0;
        }
        return 1;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int s = 0;
        int e = max(houses[houses.size() - 1], heaters[heaters.size() - 1]);
        int ans=-1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (possibleRange(houses, heaters, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};