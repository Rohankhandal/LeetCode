// // The issue is in how we're calculating the optimal path. In the current approach, we're maximizing the first robot's path, but what we actually want is to minimize what the second robot can get.
// class Solution {
// public:
//     long long gridGame(vector<vector<int>>& grid) {
//         int n = grid[0].size();
//         vector<long long> topSum(n + 1, 0);  // Prefix sum of top row
//         vector<long long> bottomSum(n + 1, 0);  // Prefix sum of bottom row
        
//         // Calculate prefix sums
//         for(int i = 0; i < n; i++) {
//             topSum[i + 1] = topSum[i] + grid[0][i];
//             bottomSum[i + 1] = bottomSum[i] + grid[1][i];
//         }
        
//         long long answer = LLONG_MAX;
//         // For each possible point where robot 1 goes down
//         for(int i = 0; i < n; i++) {
//             // After robot 1's move, robot 2 will choose the maximum of:
//             // 1. Remaining elements in top row (after point i)
//             // 2. Elements in bottom row before point i
//             long long robot2Max = max(
//                 topSum[n] - topSum[i + 1],  // Remaining in top row
//                 bottomSum[i]                 // Bottom row before i
//             );
//             answer = min(answer, robot2Max);
//         }
        
//         return answer;
//     }
// };.


// That's another way to solve it - we can minimize robot 2's options between:

// Sum of remaining top row to the right
// Sum of bottom row from start to current point
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long topRightSum = 0;  // Sum of remaining elements in top row
        long long bottomLeftSum = 0; // Sum of elements in bottom row from start
        long long answer = LLONG_MAX;
        
        // Calculate initial top right sum (excluding first element)
        for(int i = 1; i < n; i++) {
            topRightSum += grid[0][i];
        }
        
        // For each transition point
        for(int i = 0; i < n; i++) {
            // Robot 2 will take maximum of top right or bottom left
            answer = min(answer, max(topRightSum, bottomLeftSum));
            
            // Update sums for next iteration
            if(i < n-1) {
                topRightSum -= grid[0][i+1];    // Remove next element from top right
                bottomLeftSum += grid[1][i];     // Add current element to bottom left
            }
        }
        
        return answer;
    }
};