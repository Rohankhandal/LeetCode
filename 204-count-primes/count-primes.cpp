class Solution {
public:
    // Helper function to generate a boolean vector indicating prime numbers
    vector<bool> checkPrime(int n) {
        vector<bool> prime(n, true);  // Initialize all entries as true
        prime[0] = false;  // 0 is not a prime number
        prime[1] = false;  // 1 is not a prime number

        // Iterate through numbers up to the square root of n
        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {  // If i is a prime
                int j = i * i;  // Start marking multiples of i from i^2
                while (j < n) {
                    prime[j] = false;  // Mark multiple of i as non-prime
                    j += i;  // Move to the next multiple of i
                }
            }
        }

        return prime;  // Return the vector with prime status
    }

    // Function to count the number of prime numbers less than n
    int countPrimes(int n) {
        if (n <= 1) return 0;  // There are no primes less than or equal to 1

        vector<bool> prime = checkPrime(n);  // Get prime status for all numbers less than n
        int ans = 0;  // Initialize the count of prime numbers

        // Count the number of primes
        for (int i = 0; i < n; i++) {
            if (prime[i] == true) ans++;  // Increment the count if prime
        }

        return ans;  // Return the total count of primes
    }
};
