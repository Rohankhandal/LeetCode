// in the worst-case scenario (which is what Big O notation describes), the time complexity remains O(n^2).
// The space complexity is also O(n^2) due to the memoization table t[2001][2001] and the unordered_map mp which stores up to n entries.
class Solution {
public:
    int n;  // Number of stones
    unordered_map<int, int> mp;  // Map stone positions to their indices
    int t[2001][2001];  // Memoization table

    // Recursive function to determine if the frog can cross the river
    bool solve(vector<int>& stones, int curr_stone_index, int prevJump) {
        if (curr_stone_index == n-1)
            return true;  // Base case: reached the last stone

        if (t[curr_stone_index][prevJump] != -1)
            return t[curr_stone_index][prevJump];  // Return memoized result

        bool result = false;

        // Check possible next jumps: prevJump-1, prevJump, prevJump+1
        for (int nextJump = prevJump-1; nextJump <= prevJump+1; nextJump++) {
            if (nextJump > 0) {  // Ensure the jump is positive
                int next_stone = stones[curr_stone_index] + nextJump;  // Calculate next stone position

                if (mp.find(next_stone) != mp.end()) {  // If the next stone exists
                    result = result || solve(stones, mp[next_stone], nextJump);  // Recursively check from the next stone
                }
            }
        }

        return t[curr_stone_index][prevJump] = result;  // Memoize and return the result
    }

    bool canCross(vector<int>& stones) {
        if (stones[1] != 1)
            return false;  // If the first jump is not possible, return false

        n = stones.size();  // Get the number of stones
        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;  // Populate the map with stone positions and indices
        }

        memset(t, -1, sizeof(t));  // Initialize memoization table with -1

        return solve(stones, 0, 0);  // Start the recursion from the first stone with jump size 0
    }
};
