#include <bits/stdc++.h> 
using namespace std;

int find_all(int ind_m, int ind_n, vector<vector<int>> &dp, int m, int n){

	if(ind_m == m-1 and ind_n == n-1){
		// base case
		return 1;
	}

	if(ind_m == m or ind_n == n){
		//out of bound
		return 0;
	}
	if(dp[ind_m][ind_n] != -1){
		return dp[ind_m][ind_n];
	}
	// right move ya down move
	int right_ways = 0;
	if(ind_n < n-1){
		// last
		right_ways = find_all(ind_m, ind_n+1, dp, m, n);
	}
	int down_ways = 0;
	if(ind_m < m-1){
		down_ways = find_all(ind_m+1, ind_n, dp, m, n);
	}
	dp[ind_m][ind_n] = right_ways+ down_ways;

	return dp[ind_m][ind_n];
	
}
int uniquePaths(int m, int n) {
	// Write your code here.

	vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

	return find_all(0, 0, dp, m, n);
}