class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans = INT_MAX;

        for (int target = 1; target <= 6; ++target) {
            bool flag = true;
            int cnt1 = 0;
            for (int i = 0; i < n; i++) {
                if (tops[i] != target) {
                    if (bottoms[i] != target) {
                        flag = false;
                        break;
                    } else {
                        cnt1++;
                    }
                }
            }
            if (flag == false) {
                cnt1 = INT_MAX;
            }

            flag = true;
            int cnt2 = 0;
            for (int i = 0; i < n; i++) {
                if (bottoms[i] != target) {
                    if (tops[i] != target) {
                        flag = false;
                        break;
                    } else {
                        cnt2++;
                    }
                }
            }
            if (flag == false) {
                cnt2 = INT_MAX;
            }

            ans = min(ans, min(cnt1, cnt2));
        }

        if (ans == INT_MAX) return -1;
        return ans;
    }
};



// class Solution {
// public:
//     int check(int target, vector<int>& tops, vector<int>& bottoms) {
//         int rotateTop = 0, rotateBottom = 0;
//         for (int i = 0; i < tops.size(); ++i) {
//             if (tops[i] != target && bottoms[i] != target) {
//                 return INT_MAX; // Not possible
//             }
//             if (tops[i] != target) rotateTop++;
//             if (bottoms[i] != target) rotateBottom++;
//         }
//         return min(rotateTop, rotateBottom);
//     }

//     int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
//         int result = INT_MAX;
//         for (int val = 1; val <= 6; ++val) {
//             result = min(result, check(val, tops, bottoms));
//         }
//         return (result == INT_MAX) ? -1 : result;
//     }
// };
