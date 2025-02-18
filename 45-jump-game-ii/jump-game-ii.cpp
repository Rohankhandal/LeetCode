class Solution {
public:
    int jump(vector<int>& arr) {
         int n = arr.size();
    if (n <= 1) return 0; // Already at the end
    if (arr[0] == 0) return -1; // Cannot move forward

    int jumps = 0, left = 0, right = 0;

    while (right < n - 1) {
        int farthest = 0;

        for (int i = left; i <= right; i++) {
            farthest = max(i + arr[i], farthest);
        }

        if (farthest <= right) return -1; // Cannot progress further

        left = right + 1;
        right = farthest;
        jumps++;
    }

    return jumps;
    }
};