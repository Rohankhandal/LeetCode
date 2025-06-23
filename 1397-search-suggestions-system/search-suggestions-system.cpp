// ⏱️ Time Complexity:
// Sorting: O(n log n)
// For each character in searchWord:
// In worst case, both start and end can scan the array once over all characters ⇒ O(n) total
// Collecting 3 results is constant O(1)
// Suppose m = searchWord.length
// ➡️ Total Time: O(n log n + n + m * 3) = O(n log n + m)

// \U0001f4e6 Space Complexity:
// Sorting in-place: O(1) extra
// Result list: O(m * 3) = O(m)
// No extra data structures.
// ➡️ Total Space: O(m)
class Solution {
public:
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());

        int n = products.size();
        vector<vector<string>> result;
        int start = 0, end = n - 1;

        string prefix = "";
        for (char ch : searchWord) {
            prefix += ch;

            // Narrow down start
            while (start <= end && 
                   (products[start].size() < prefix.size() || products[start].substr(0, prefix.size()) != prefix)) {
                start++;
            }

            // Narrow down end
            while (start <= end && 
                   (products[end].size() < prefix.size() || products[end].substr(0, prefix.size()) != prefix)) {
                end--;
            }

            // Collect up to 3 suggestions
            vector<string> suggestions;
            for (int i = start; i <= end && i < start + 3; ++i) {
                suggestions.push_back(products[i]);
            }

            result.push_back(suggestions);
        }

        return result;
    }
};

// 1. Building the Trie: O(N × M)

// N = number of products
// M = average length of each product
// For each product, we traverse character by character to insert it into the trie
// Total: O(N × M)

// 2. Processing Each Prefix: O(L × (3 + T))

// L = length of searchWord
// For each character in searchWord:

// Navigation: O(1) to move to the next trie node
// DFS Search: O(3 + T) where T is the number of trie nodes traversed



// 3. DFS Traversal Details
// The DFS function has an interesting complexity:

// Best Case: O(3) - when we find 3 suggestions quickly
// Worst Case: O(T) where T is the total number of nodes in the subtree
// Practical Case: O(3 + nodes_visited_before_finding_3_words)

// The key optimization is the early termination: if (res.size() == 3) return;
// 4. Overall Time Complexity
// Total: O(N × M + L × (3 + T))
// Where:

// N = number of products
// M = average product length
// L = length of searchWord
// T = average number of trie nodes explored per prefix (bounded by early termination)



// 6. Space Complexity

// Trie Storage: O(N × M) for storing all products
// Recursion Stack: O(M) for DFS depth
// Result Storage: O(L × 3) = O(L)



// class Solution {
// public:
//     struct TrieNode {
//         TrieNode* children[26] = {nullptr};
//         bool isEnd = false;
//         string word;
//     };

//     TrieNode* getNode() {
//         return new TrieNode();
//     }

//     void insert(TrieNode* root, const string& word) {
//         TrieNode* node = root;
//         for (char ch : word) {
//             int idx = ch - 'a';
//             if (!node->children[idx])
//                 node->children[idx] = getNode();
//             node = node->children[idx];
//         }
//         node->isEnd = true;
//         node->word = word;
//     }

//     void dfs(TrieNode* node, vector<string>& res) {
//         if (!node || res.size() == 3) return;
//         if (node->isEnd) res.push_back(node->word);
//         for (int i = 0; i < 26; ++i) {
//             if (node->children[i]) {
//                 dfs(node->children[i], res);
//                 if (res.size() == 3) return;  // early stop if we have 3 suggestions
//             }
//         }
//     }

//     vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
//         TrieNode* root = getNode();
//         for (const string& product : products)
//             insert(root, product);

//         vector<vector<string>> result;
//         TrieNode* node = root;
//         for (char ch : searchWord) {
//             int idx = ch - 'a';
//             if (node) node = node->children[idx];
//             if (node) {
//                 vector<string> suggestions;
//                 dfs(node, suggestions);
//                 result.push_back(suggestions);
//             } else {
//                 result.push_back({});
//             }
//         }

//         return result;
//     }
// };
