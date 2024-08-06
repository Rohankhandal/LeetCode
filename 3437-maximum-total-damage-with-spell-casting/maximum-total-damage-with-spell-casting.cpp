class Solution {
public:
    // Recursive function with memoization to find the maximum damage
    long long solve(vector<int>& uniqueEle, int i, vector<long long>& dp, map<int, int>& mp) {
        int n = uniqueEle.size();
        if (i >= n) return 0; // Base case: end of the array

        if (dp[i] != -1) return dp[i]; // Return memoized result if available

        long long take = 0;
        int nextIdx = i + 1;

        // Find the next index that doesn't conflict with the current element
        while (nextIdx < n && (uniqueEle[nextIdx] == uniqueEle[i] + 1 || uniqueEle[nextIdx] == uniqueEle[i] + 2)) nextIdx++;

        // Include the current element and its frequency in the damage calculation
        take = 1LL * uniqueEle[i] * mp[uniqueEle[i]] + solve(uniqueEle, nextIdx, dp, mp);

        // Calculate damage if the current element is not taken
        long long noTake = solve(uniqueEle, i + 1, dp, mp);

        // Memoize and return the maximum damage between taking and not taking the current element
        dp[i] = max(take, noTake);
        return dp[i];
    }

    // Main function to calculate the maximum total damage
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> mp;
        // Count the frequency of each element
        for (const auto& it : power) {
            mp[it]++;
        }

        std::vector<int> uniqueEle;
        // Extract unique elements and sort them
        for (const auto& it : mp) {
            uniqueEle.push_back(it.first);
        }

        int n = uniqueEle.size();
        vector<long long> dp(n, -1); // Initialize dp array with -1
        return solve(uniqueEle, 0, dp, mp); // Start solving from the first element
    }
};