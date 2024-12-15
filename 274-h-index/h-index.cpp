class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        // Create a frequency array to store citation counts
        vector<int> freq(n + 1, 0);
        
        // Count the frequency of each citation count
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n) 
                freq[n]++;
            else 
                freq[citations[i]]++;
        }
        
        // Compute the suffix sum of frequencies
        for (int i = n - 1; i >= 0; i--) {
            freq[i] += freq[i + 1];
        }
        
        // Find the highest H-index such that freq[i] >= i
        for (int i = n; i >= 0; i--) {
            if (freq[i] >= i) return i;
        }
        
        return 0;  // If no valid H-index found, return 0
    }
};


