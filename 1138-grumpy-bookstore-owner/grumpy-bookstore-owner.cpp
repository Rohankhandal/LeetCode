// Approach - Sliding Window
// T.C : O(n)
// S.C : O(1)
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size(); // Number of elements in the customers array
        int unsat = 0; // Variable to track unsatisfied customers in the current window

        // Calculate initial unsatisfied customers in the first 'minutes' window
        for (int i = 0; i < minutes; i++) {
            unsat += customers[i] * grumpy[i];
        }

        int maxUnsat = unsat; // Initialize maxUnsat to the value of the initial window

        // Use two pointers i and j to define the sliding window of size 'minutes'
        int i = 0;
        int j = minutes;

        // Slide the window across the array
        while(j < n) {
            unsat += customers[j] * grumpy[j]; // Include current element in the window
            unsat -= customers[i] * grumpy[i]; // Remove the element going out of the window
            
            maxUnsat = max(maxUnsat, unsat); // Update maxUnsat if current window has more unsatisfied customers
            i++;
            j++;
        }

        int totalCustomers = maxUnsat; // Initialize total customers with the maximum converted unsatisfied customers

        // Calculate total satisfied customers
        for (int i = 0; i < n; i++) {
            totalCustomers += customers[i] * (1 - grumpy[i]); // Add customers who are satisfied regardless of the grumpy state
        }

        return totalCustomers; // Return the maximum number of satisfied customers
    }
};
