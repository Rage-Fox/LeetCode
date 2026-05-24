class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size(),ans = -1e9;
        // Strictly interior single cells
        for(int i = 1; i < n - 1; i++) {
            for(int j = 1; j < m - 1; j++) {
                ans = max(ans, grid[i][j]);
            }
        }
        // Kadane's for Rows
        for(int i = 0; i < n; i++) {
            int mx = -1e9, sum = grid[i][0];
            for(int j = 1; j < m; j++) {
                mx = max(mx, sum + grid[i][j]);
                sum = max(grid[i][j], sum + grid[i][j]);
            }
            ans = max(ans, mx);
        }
        // Kadane's for Columns
        for(int j = 0; j < m; j++) {
            int mx = -1e9, sum = grid[0][j];
            for(int i = 1; i < n; i++) {
                mx = max(mx, sum + grid[i][j]);
                sum = max(grid[i][j], sum + grid[i][j]);
            }
            ans = max(ans, mx);
        }
        return ans;
    }
};