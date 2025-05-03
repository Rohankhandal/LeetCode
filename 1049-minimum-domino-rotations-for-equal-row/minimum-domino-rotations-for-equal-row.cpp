class Solution {
public:
    int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int rotateTop = 0, rotateBottom = 0;
        for (int i = 0; i < tops.size(); ++i) {
            if (tops[i] != target && bottoms[i] != target) {
                return INT_MAX; // Not possible
            }
            if (tops[i] != target) rotateTop++;
            if (bottoms[i] != target) rotateBottom++;
        }
        return min(rotateTop, rotateBottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = INT_MAX;
        for (int val = 1; val <= 6; ++val) {
            result = min(result, check(val, tops, bottoms));
        }
        return (result == INT_MAX) ? -1 : result;
    }
};
