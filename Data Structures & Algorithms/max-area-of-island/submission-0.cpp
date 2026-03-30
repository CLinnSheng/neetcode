class Solution {
public:
    const std::vector<std::pair<int, int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        if (grid.empty()) return 0;

        int n_row = grid.size();
        int n_col = grid[0].size();
        int maxArea = 0;

        std::function<int(const int&, const int&)> dfs = [&](const int& row, const int& col) {
            
            if (row < 0 || col < 0 || row >= n_row || col >= n_col || !grid[row][col])
                return 0;

            grid[row][col] = 0;
            int area = 1;

            for (const auto& [_row, _col] : DIRECTIONS) {
                auto new_row = _row + row;
                auto new_col = _col + col;

                area += dfs(new_row, new_col);
            }
            return area;
        };
        for (int row = 0; row < n_row; row++)
            for (int col = 0; col < n_col; col++)
                maxArea = std::max(maxArea, dfs(row, col));

        return maxArea;   
    }
};
