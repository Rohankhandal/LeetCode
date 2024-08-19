#include <climits>

class Solution {
public:
    int solve(int n, int noOfA, int copyA) {
        if (noOfA > n) return 1000; // If noOfA exceeds n, return INT_MAX (invalid state)
        if (noOfA == n) return 0;      // Base case: when we have exactly n 'A's, no more steps needed

        // Try to paste the copied segment
        int paste =1+  solve(n, noOfA + copyA, copyA);
     

        // Try to copy the current segment and then paste
        int copyPaste = 1 + 1 + solve(n, noOfA+noOfA, noOfA);
         // Adding 2 steps: one for copy and one for paste

        return min(paste, copyPaste); // Return minimum steps required
    }

    int minSteps(int n) {
        if (n == 1) return 0; // If n is 1, no steps are needed
        return 1+solve(n, 1, 1); // Start with 1 'A', no copy initially, +1 for first copy operation
       
    }
};
