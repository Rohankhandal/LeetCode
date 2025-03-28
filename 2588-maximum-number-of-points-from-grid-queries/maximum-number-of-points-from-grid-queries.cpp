class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
    vector<int> sortedQueries = queries;
    sort(sortedQueries.begin(), sortedQueries.end());
    
    vector<int> answer(queries.size());
    unordered_map<int, int> queryResults;
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    
    pq.push({grid[0][0], {0, 0}});
    visited[0][0] = true;
    
    int count = 0;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for (int query : sortedQueries) {
        while (!pq.empty() && pq.top().first < query) {
            auto [value, pos] = pq.top();
            pq.pop();
            int r = pos.first, c = pos.second;
            count++;
            
            for (auto &dir : directions) {
                int nr = r + dir[0], nc = c + dir[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    pq.push({grid[nr][nc], {nr, nc}});
                    visited[nr][nc] = true;
                }
            }
        }
        queryResults[query] = count;
    }
    
    for (int i = 0; i < queries.size(); i++) {
        answer[i] = queryResults[queries[i]];
    }
    
    return answer;
    }
};