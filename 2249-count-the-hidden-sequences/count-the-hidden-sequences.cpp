// class Solution {
// public:
//     typedef long long ll;
//     bool isPossible(vector<int>& differences, ll tar, ll lower, ll upper) {
//         int fVal = tar;
//         for (int i = 0; i < differences.size(); i++) {
//             fVal += differences[i];
//             if (fVal < lower || fVal > upper) {
//                 return false;
//             }
//         }
//         return true;
//     }

//     int numberOfArrays(vector<int>& differences, int lower, int upper) {
//         // compute prefix sum bounds
//         long long minPrefix = 0, maxPrefix = 0, sum = 0;
//         for (int diff : differences) {
//             sum += diff;
//             minPrefix = min(minPrefix, sum);
//             maxPrefix = max(maxPrefix, sum);
//         }

//         ll l = lower - minPrefix;
//         ll r = upper - maxPrefix;

//         ll leftBound = INT_MAX, rightBound = INT_MIN;

//         // Left bound
//         ll lo = l, hi = r;
//         while (lo <= hi) {
//             ll mid = lo + (hi - lo) / 2;
//             if (isPossible(differences, mid, lower, upper)) {
//                 leftBound = mid;
//                 hi = mid - 1;
//             } else {
//                 lo = mid + 1;
//             }
//         }

//         // Right bound
//         lo = l, hi = r;
//         while (lo <= hi) {
//             ll mid = lo + (hi - lo) / 2;
//             if (isPossible(differences, mid, lower, upper)) {
//                 rightBound = mid;
//                 lo = mid + 1;
//             } else {
//                 hi = mid - 1;
//             }
//         }

//         if (leftBound == INT_MAX || rightBound == INT_MIN) return 0;
//         return rightBound - leftBound + 1;
//     }
// };



class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long minPref = 0, maxPref = 0, sum = 0;

        for (int diff : differences) {
            sum += diff;
            minPref = min(minPref, sum);
            maxPref = max(maxPref, sum);
        }

        long long minStart = lower - minPref;
        long long maxStart = upper - maxPref;

        return max(0LL, maxStart - minStart + 1);
    }
};
