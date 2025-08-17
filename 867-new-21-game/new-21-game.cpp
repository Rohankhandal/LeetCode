class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // Edge cases:
        // 1. If k is 0, Alice stops immediately at 0 points. Prob is 1.0.
        // 2. If n is large enough to cover all possible outcomes (max score is k-1 + maxPts),
        //    the probability is also 1.0.
        if (k == 0 || n >= k + maxPts - 1) {
            return 1.0;
        }

        // dp[i] will store the probability of having a score of i.
        std::vector<double> dp(n + 1);
        dp[0] = 1.0;
        
        // windowSum stores the sum of probabilities of scores from which Alice can still draw.
        double windowSum = 1.0;
        double result = 0.0;

        for (int i = 1; i <= n; ++i) {
            // The probability of reaching score i is the sum of probabilities of valid previous
            // scores (windowSum) divided by the number of possible outcomes (maxPts).
            dp[i] = windowSum / maxPts;

            if (i < k) {
                // If score i is less than k, Alice continues playing.
                // This score's probability is added to the window for future calculations.
                windowSum += dp[i];
            } else {
                // If score i is k or more, Alice stops. This is a final state.
                // We add its probability to our final result.
                result += dp[i];
            }
            
            if (i >= maxPts) {
                // The score (i - maxPts) is now sliding out of our window of possible previous scores.
                // We must subtract its probability from windowSum, but only if it was a "continue playing"
                // score (i.e., less than k), as only those were added to windowSum.
                if (i - maxPts < k) {
                   windowSum -= dp[i - maxPts];
                }
            }
        }
        
        return result;
    }
};