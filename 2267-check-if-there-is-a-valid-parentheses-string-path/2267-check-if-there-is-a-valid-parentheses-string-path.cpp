class Solution {
public:
    bool f(int i, int j, int curr, vector<vector<char>>& grid,
           vector<vector<vector<int>>>& dp) {
        if (grid[i][j] == '(')
            curr++;
        else
            curr--;
        if (curr < 0)
            return false;
        if (i == grid.size() - 1 and j == grid[0].size() - 1)
            return curr == 0;
        if (dp[i][j][curr] != -1)
            return dp[i][j][curr];
        bool res = false;
        if (i < grid.size() - 1) {
            res = f(i + 1, j, curr, grid, dp);
        }
        if (res)
            return dp[i][j][curr] = res;
        if (j < grid[0].size() - 1) {
            res = f(i, j + 1, curr, grid, dp);
        }
        return dp[i][j][curr] = res;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(m + n + 1, -1)));
        return f(0, 0, 0, grid, dp);
    }
};