#include <bits/stdc++.h> 
using namespace std;

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // 3D DP array initialized with -1 (to indicate uncomputed state)
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        
        return fun(0, 0, m - 1, n, m, grid, dp);
    }

    int fun(int row, int col1, int col2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        // Out of bounds
        if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m)
            return INT_MIN;

        // Base case: last row
        if (row == n - 1) {
            if (col1 == col2)
                return grid[row][col1];
            else
                return grid[row][col1] + grid[row][col2];
        }

        // Memoized result
        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        int maxCherries = INT_MIN;

        // Explore all 9 movement combinations
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                int newCol1 = col1 + d1;
                int newCol2 = col2 + d2;
                int nextMove = fun(row + 1, newCol1, newCol2, n, m, grid, dp);
                maxCherries = max(maxCherries, nextMove);
            }
        }

        int currentCherries = (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];

        return dp[row][col1][col2] = currentCherries + maxCherries;
    }
};
