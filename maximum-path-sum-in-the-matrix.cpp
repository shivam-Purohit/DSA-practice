#include <bits/stdc++.h> 
using namespace std;

int get_min(int ind_row, int ind_col, vector<vector<int>>&dp, vector<vector<int>> &matrix, int row, int col){
    if(ind_row == row-1){
        return matrix[ind_row][ind_col];
    }

    if(dp[ind_row][ind_col] != -1){
        return dp[ind_row][ind_col];
    }

    int down = INT_MIN;

    if(ind_row < row-1){
        down = get_min(ind_row+1, ind_col, dp, matrix, row, col);
    }
    int down_right = INT_MIN;

    if(ind_col < col-1){
        down_right =  get_min(ind_row+1, ind_col+1, dp, matrix, row, col);
    }
    int down_left = INT_MIN;
    if(ind_col > 0){
        down_left =  get_min(ind_row+1, ind_col-1, dp, matrix, row, col);
    }
    dp[ind_row][ind_col] = matrix[ind_row][ind_col] + max(down, max(down_left, down_right));

    return dp[ind_row][ind_col];
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int row = matrix.size();
    int col = matrix[0].size();
    int maxi= INT_MIN;
    vector<vector<int>>dp (row, vector<int> (col, -1));
    for(int i = 0; i < col; i++){
        int temp = get_min(0, i, dp, matrix, row, col);
        maxi= max(temp, maxi);
    }

    return maxi;


}