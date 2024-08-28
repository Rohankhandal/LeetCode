// Now, let's consider the total number of possible combinations:

// We have 4 digits, each can be 0-9.
// Total combinations = 10 * 10 * 10 * 10 = 10,000

// In the worst case, we might need to explore all combinations except the deadends.
// Therefore, the time complexity is O(N * M), where:

// N is the number of possible combinations (10,000 in this case)
// M is the number of operations per combination (which is 8 in our case, but we can consider it constant)

// So, we can simplify it to O(N), where N is 10,000.
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // Convert deadends to a set for efficient lookup
        unordered_set<string> deadList(deadends.begin(), deadends.end());

        // Check if starting position is a deadend
        if (deadList.count("0000")) return -1;

        unordered_map<string, bool> visited;
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        visited["0000"] = true;

        while (!q.empty()) {
            string combination = q.front().first;
            int moves = q.front().second;
            q.pop();

            // Check if target is reached
            if (combination == target) return moves;

            // Try changing each digit
            for (int i = 0; i < 4; i++) {
                for (int delta = -1; delta <= 1; delta += 2) {
                    // Calculate new digit (wrapping around 0-9)
                    int newDigit = ((combination[i] - '0') + delta + 10) % 10;
                    string newCombination = combination;
                    newCombination[i] = (newDigit + '0');

                    // Check if new combination is valid and unvisited
                    if (deadList.find(newCombination) == deadList.end() && 
                        visited.find(newCombination) == visited.end()) {
                        visited[newCombination] = true;
                        q.push({newCombination, moves + 1});
                    }
                }
            }
        }

        // Target unreachable
        return -1;
    }
};