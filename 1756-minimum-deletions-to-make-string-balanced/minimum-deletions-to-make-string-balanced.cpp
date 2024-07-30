class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();  // Get the size of the string
        
        // Initialize vectors to keep track of cumulative counts of 'a' and 'b'
        vector<int> A(n, 0);
        vector<int> B(n, 0);
        
        int countA = 0, countB = 0;
        
        // First pass: count 'a' characters from the left
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') countA++;
            A[i] = countA;
        }
        
        // Second pass: count 'b' characters from the right
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'b') countB++;
            B[i] = countB;
        }
        
        int maxi = INT_MIN;
        
        // Calculate the maximum number of balanced characters
        for (int i = 0; i < n; i++) {
            int sum = A[i] + B[i];
            maxi = max(maxi, sum);
        }
        
        // Return the minimum number of deletions to balance the string
        return n - maxi;
    }
};
