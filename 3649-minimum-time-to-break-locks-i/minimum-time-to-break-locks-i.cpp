class Solution {
public:
    int findMinimumTime(vector<int>& strength, int k) {
        int n = strength.size();
    vector<int> perm = strength; // Create a copy for permutations
    int minTime = INT_MAX;

    // Try all permutations of the lock order
    sort(perm.begin(), perm.end());
    do {
        int time = 0;
        int energy = 0;
        int x = 1;

        for (int i = 0; i < n; ++i) {
            int required = perm[i];

              // Calculate the time to reach the required energy
            if (energy < required) {
                time += (required ) / x+(required%x!=0); // Ceiling division
                energy = required;
            }

            // Break the lock
            energy = 0; // Reset energy
            x += k;     // Increase factor x
        }

        minTime = min(minTime, time);

    } while (next_permutation(perm.begin(), perm.end()));

    return minTime;
    }
};