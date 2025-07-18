#include <bits/stdc++.h> 

using namespace std;
int get_min(int ind_rows, int ind_cols, vector<vector<int>> &dp,int rows, int cols, vector<vector<int>> &grid){

    if(ind_rows == rows-1 and ind_cols == cols-1){
        return grid[ind_rows][ind_cols];
    }

    if(dp[ind_rows][ind_cols] != -1){
        return dp[ind_rows][ind_cols];
    }
    
    int down_sum = INT_MAX;
    if (ind_rows < rows-1){
        down_sum = get_min(ind_rows+1, ind_cols, dp, rows, cols, grid);
    }
    int right_sum = INT_MAX;
    if (ind_cols < cols-1){
        right_sum = get_min(ind_rows, ind_cols + 1, dp, rows, cols, grid);
    }
    dp[ind_rows][ind_cols] = grid[ind_rows][ind_cols] + min(down_sum, right_sum);

    return dp[ind_rows][ind_cols];
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int rows = grid.size();
    int cols= grid[0].size();

    vector<vector<int>> dp (rows, vector<int>(cols, -1));

    return get_min(0, 0, dp, rows, cols, grid);
}