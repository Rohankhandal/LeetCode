class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks_count = 0;
        int max_so_far = -1;

        for (int i = 0; i < arr.size(); i++) {
            max_so_far = max(max_so_far, arr[i]);
            if (max_so_far == i) {
                chunks_count++;
            }
        }

        return chunks_count;
    }
};