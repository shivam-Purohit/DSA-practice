#include <bits/stdc++.h> 
using namespace std;

int find_min(int ind_row, int ind_col, vector<vector<int>> &dp, vector<vector<int>> &triangle, int row){
	if(ind_row == row-1){
		return triangle[ind_row][ind_col];
	}
	if(dp[ind_row][ind_col] != -1){
		return dp[ind_row][ind_col];
	}
	int down = INT_MAX;
	int down_right = INT_MAX;

	down = find_min(ind_row+1, ind_col, dp, triangle, row);

	down_right = find_min(ind_row+1, ind_col+1, dp, triangle, row);

	dp[ind_row][ind_col] = triangle[ind_row][ind_col] + min(down, down_right);

	return dp[ind_row][ind_col];
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.

	int row = triangle.size();
	// int col = triangle[0].size();

	vector<vector<int>> dp(row, vector<int> (row, -1));

	return find_min(0, 0, dp, triangle, row);
}