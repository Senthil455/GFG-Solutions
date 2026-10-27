char** createGrid(int m, int n, int* returnSize) {
    *returnSize = m;
    char** grid = malloc(m * sizeof(char*));
    for (int i = 0; i < m; i++) {
        grid[i] = malloc((n+1) * sizeof(char));
        grid[i][0] = '.';
        for (int j = 1; j < n; j++) {
            grid[i][j] = '#';
        }
        grid[i][n] = '\0';
    }
    for (int j = 1; j < n; j++) {
        grid[m-1][j] = '.';
    }
    return grid;
}