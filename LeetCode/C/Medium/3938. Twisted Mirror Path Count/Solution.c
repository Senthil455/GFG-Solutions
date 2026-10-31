int uniquePaths(int** grid, int gridSize, int* gridColSize) {
    const int MOD = 1000000007;

    int m = gridSize;
    int n = gridColSize[0];

    int (*dp)[n][2] = calloc(m, sizeof(*dp));

    // Starting position
    dp[0][0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            for (int d = 0; d < 2; d++) {

                int ways = dp[i][j][d];

                if (ways == 0)
                    continue;

                if (grid[i][j] == 0) {

                    // Move right
                    if (j + 1 < n) {
                        dp[i][j + 1][0] =
                            (dp[i][j + 1][0] + ways) % MOD;
                    }

                    // Move down
                    if (i + 1 < m) {
                        dp[i + 1][j][1] =
                            (dp[i + 1][j][1] + ways) % MOD;
                    }

                } else {

                    // Mirror: entered while moving right
                    // Reflection changes direction to down
                    if (d == 0 && i + 1 < m) {
                        dp[i + 1][j][1] =
                            (dp[i + 1][j][1] + ways) % MOD;
                    }

                    // Mirror: entered while moving down
                    // Reflection changes direction to right
                    else if (d == 1 && j + 1 < n) {
                        dp[i][j + 1][0] =
                            (dp[i][j + 1][0] + ways) % MOD;
                    }
                }
            }
        }
    }

    int ans = (dp[m - 1][n - 1][0] +
               dp[m - 1][n - 1][1]) % MOD;

    free(dp);

    return ans;
}