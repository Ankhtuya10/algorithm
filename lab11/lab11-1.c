#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int rows, cols;
int grid[MAX_ROWS][MAX_COLS];
int visited[MAX_ROWS][MAX_COLS];

int dfs(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) {
        return 1;
    }
    if (visited[r][c]) {
        return 0;
    }

    visited[r][c] = 1;
    int perimeter = 0;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; i++) {
        int dr = directions[i][0];
        int dc = directions[i][1];
        perimeter += dfs(r + dr, c + dc);
    }
    return perimeter;
}

int islandPerimeter(int grid[][MAX_COLS], int r, int c) {
    rows = r;
    cols = c;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            visited[i][j] = 0;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                return dfs(i, j);
            }
        }
    }

    return 0;  
}

int main() {
    int grid[4][4] = {
        {0, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 1}
    };
    int rows = 4, cols = 4;
    printf("Island perimeter: %d\n", islandPerimeter(grid, rows, cols));
    return 0;
}