class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (targetCapacity > jug1Capacity + jug2Capacity) return false;
        if (targetCapacity == 0) return true;

        int g = gcd(jug1Capacity, jug2Capacity);
        return (targetCapacity % g == 0);
    }
};



// // ⏱ Time Complexity
// // Worst-case states: O(x + y)

// // Each state is visited once → Time: O(x + y)

// // Space: O(x + y) for queue and visited set
// class Solution {
// public:
//     bool canMeasureWater(int x, int y, int target) {
//         queue<int> q;
//         unordered_set<int> visit;

//         q.push(0);
//         visit.insert(0);

//         vector<int> dir {x, -x, y, -y};

//         while (!q.empty()) {
//             int val = q.front(); q.pop();

//             if (val == target) return true;

//             for (auto &d : dir) {
//                 int next = val + d;

//                 // ✅ Only consider valid, non-negative and not too large values
//                 if (next >= 0 && next <= x + y && !visit.count(next)) {
//                     q.push(next);
//                     visit.insert(next);
//                 }
//             }
//         }

//         return false;
//     }
// };
