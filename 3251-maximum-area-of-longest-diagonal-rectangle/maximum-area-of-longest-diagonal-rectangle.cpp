class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        long long maxDiaSq = 0;  // store diagonal squared to avoid precision issues

        for (auto &it : dimensions) {
            long long l = it[0];
            long long w = it[1];
            long long diaSq = l * l + w * w;  // no sqrt needed
            int area = l * w;

            if (diaSq > maxDiaSq) {
                // new longer diagonal found
                maxDiaSq = diaSq;
                ans = area;
            } 
            else if (diaSq == maxDiaSq) {
                // same longest diagonal → pick larger area
                ans = max(ans, area);
            }
        }
        return ans;
    }
};
