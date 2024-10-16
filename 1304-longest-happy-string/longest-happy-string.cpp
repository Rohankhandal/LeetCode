class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Create a vector of pairs representing the character and their remaining count
    vector<pair<int, char>> freq = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
    string result = "";
    
    // Loop until no more characters can be added
    while (true) {
        // Sort the characters by remaining count in descending order
        sort(freq.rbegin(), freq.rend());
        
        bool added = false;
        
        // Try to add the character with the highest count that doesn't violate the rules
        for (auto &[count, ch] : freq) {
            // Check if we can add this character without creating three consecutive same characters
            if (count > 0 && (result.size() < 2 || result[result.size() - 1] != ch || result[result.size() - 2] != ch)) {
                result += ch;  // Append the character
                --count;       // Decrease its remaining count
                added = true;  // Mark that we added a character
                break;
            }
        }
        
        // If no character could be added, break the loop
        if (!added) break;
    }
    
    return result;  // Return the resulting string
    }
};