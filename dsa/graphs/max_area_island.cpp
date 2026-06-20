class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    int count = 0;
                    dfs(grid, i, j, count);
                    res = max(res, count);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& grid, int i, int j, int& count) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
            return;
        }
        grid[i][j] = 0;
        count++;
        dfs(grid, i + 1, j, count);
        dfs(grid, i - 1, j, count);
        dfs(grid, i, j + 1, count);
        dfs(grid, i, j - 1, count);
    }
};