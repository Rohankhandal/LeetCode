class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        // Immediate checks for simple cases
        if (x + y == target || x == target || y == target) return true;

        // If the combined capacity is less than the target
        if (x + y < target) return false;

        set<int> visited;        // Set to track visited states
        vector<int> dir = {x, -x, y, -y};  // Possible operations on current state
        queue<int> q;            // Queue for BFS
        q.push(0);
        visited.insert(0);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == target) return true;  // Found a solution

            for (auto d : dir) {
                int temp = curr + d;
                // Check if the new state is valid and not visited
                if (temp >= 0 && temp <= (x + y) && !visited.count(temp)) {
                    q.push(temp);
                    visited.insert(temp);
                }
            }
        }

        return false;  // No solution found
    }
};