class DisJointSet {
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

public:
    DisJointSet(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int num) {
        if (parent[num] == num) return num;
        return parent[num] = find(parent[num]);
    }

    void UnionBySize(int x, int y) {
        int xParent = find(x);
        int yParent = find(y);

        if (xParent != yParent) {
            if (size[xParent] > size[yParent]) {
                parent[yParent] = xParent;
                size[xParent] += size[yParent];
            } else {
                parent[xParent] = yParent;
                size[yParent] += size[xParent];
            }
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;

        // Find the maximum row and column values
        for (auto &it : stones) {
            maxRow = max(it[0], maxRow);
            maxCol = max(it[1], maxCol);
        }

        // Initialize DisJointSet with appropriate size
        DisJointSet ds(maxRow + maxCol + 2);

        unordered_map<int, int> componentCount;

        // Union the stones based on their row and column
        for (auto &it : stones) {
            int newR = it[0];
            int newC = it[1] + maxRow + 1;  // Shift the columns by maxRow + 1
            ds.UnionBySize(newR, newC);

        }
        for(auto &it:stones)
        {
            int newR=it[0];
            // Find and track the root parent of the connected component
            int parent = ds.find(newR);
            componentCount[parent]++;
        }

        // The number of stones that can be removed is the total number of stones
        // minus the number of connected components
        return n - componentCount.size();
    }
};
