class TreeAncestor {
public:
    const int LOG = 31;
    vector<vector<int>> up;

    TreeAncestor(int n, vector<int>& parent) {
        up = vector<vector<int>> (LOG, vector<int>(n + 5, -1));
        
        for(int i = 0; i < n; ++i)
            up[0][i] = parent[i];

        for(int j = 1; j < LOG; ++j) 
            for(int i = 0; i < n; ++i)
                if(up[j - 1][i] != -1)
                    up[j][i] = up[j - 1][up[j - 1][i]];
    }
    
    int getKthAncestor(int node, int k) {
        for(int j = 0; j < LOG; ++j) {
            if((k >> j) & 1) {
                node = up[j][node];

                if(node == -1)
                    break;
            }
        }

        return node;
    }
};