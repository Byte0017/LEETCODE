// Approach 1:Backtracking(track all possible condition)
// Give TLE


class Solution {
public:
    bool check(vector<vector<int>>& grid, int r, int c, int i, int j, int val) {
        return (i >= 0 && j >= 0 && i < r && j < c && grid[i][j] > val);
    }

    void solve(vector<vector<int>>& grid, int r, int c, int& maxMove, int cnt, int i, int j) {
        // Base case: Out of bounds or reached maximum column
        if (i < 0 || j < 0 || i >= r || j >= c) return;
        maxMove = max(cnt, maxMove);

        // Stop if maximum column is reached
        if (maxMove == c-1) return;

        // Explore in three directions if the next cell has a greater value
        if (check(grid, r, c, i - 1, j + 1, grid[i][j])) {
            solve(grid, r, c, maxMove, cnt + 1, i - 1, j + 1);
        }
        if (check(grid, r, c, i, j + 1, grid[i][j])) {
            solve(grid, r, c, maxMove, cnt + 1, i, j + 1);
        }
        if (check(grid, r, c, i + 1, j + 1, grid[i][j])) {
            solve(grid, r, c, maxMove, cnt + 1, i + 1, j + 1);
        }
    }

    int maxMoves(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int maxMove = 0;
        
        for (int row = 0; row < r; row++) {
            solve(grid, r, c, maxMove, 0, row, 0);
            if (maxMove == c-1) {
                break; // maxMove is achieved, equal to c - 1
            }
        }
        return maxMove;
    }
};

//Approach 2: Using DP
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> dp(r, vector<int>(c, 0));
        
        // store from c-2 column
        for (int j = c - 2; j >= 0; j--) {
            for (int i = 0; i < r; i++) {
                int maxMove = 0;

                if (j + 1 < c && grid[i][j] < grid[i][j + 1]) {
                    maxMove = max(maxMove, 1 + dp[i][j + 1]);
                }
                if (i > 0 && j + 1 < c && grid[i][j] < grid[i - 1][j + 1]) {
                    maxMove = max(maxMove, 1 + dp[i - 1][j + 1]);
                }
                if (i + 1 < r && j + 1 < c && grid[i][j] < grid[i + 1][j + 1]) {
                    maxMove = max(maxMove, 1 + dp[i + 1][j + 1]);
                }
                dp[i][j] = maxMove;
            }
        }

        // Find the maximum moves starting from the first column across all rows
        int maxMoveResult = 0;
        for (int i = 0; i < r; i++) {
            maxMoveResult = max(maxMoveResult, dp[i][0]);
        }
        return maxMoveResult == 0 ? 0 : maxMoveResult;
    }
};