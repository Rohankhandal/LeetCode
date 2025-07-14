class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        queue<int> q;
        unordered_set<int> visit;

        q.push(0);
        visit.insert(0);

        vector<int> dir {x, -x, y, -y};

        while (!q.empty()) {
            int val = q.front(); q.pop();

            if (val == target) return true;

            for (auto &d : dir) {
                int next = val + d;

                // ✅ Only consider valid, non-negative and not too large values
                if (next >= 0 && next <= x + y && !visit.count(next)) {
                    q.push(next);
                    visit.insert(next);
                }
            }
        }

        return false;
    }
};
