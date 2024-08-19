//T.c:-O(2^N) and S.c:-O(N)
// class Solution {
// public:
//     int solve(int n, int noOfA, int copyA) {
//         if (noOfA > n) return 1000; // If noOfA exceeds n, return 1000 (invalid state)
//         if (noOfA == n) return 0;      // Base case: when we have exactly n 'A's, no more steps needed

//         // Try to paste the copied segment
//         int paste =1+  solve(n, noOfA + copyA, copyA);
     
//         // Try to copy the current segment and then paste
//         int copyPaste = 1 + 1 + solve(n, noOfA+noOfA, noOfA);
//          // Adding 2 steps: one for copy and one for paste

//         return min(paste, copyPaste); // Return minimum steps required
//     }

//     int minSteps(int n) {
//         if (n == 1) return 0; // If n is 1, no steps are needed
//         return 1+solve(n, 1, 1); // Start with 1 'A', no copy initially, +1 for first copy operation
       
//     }
// };



//Bottom UP Approach
class Solution {
public:

    int minSteps(int n) {
        vector<int>dp(n+1,0);

        for(int i=2;i<=n;i++)
        {
            dp[i]=i;
        }

        for(int i=4;i<=n;i++)
        {
            for(int j=2;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    dp[i]=min(dp[i],i/j+dp[j]);
                    dp[i]=min(dp[i],j+dp[i/j]);
                }
            }
        }
        return dp[n];
       
    }
};
