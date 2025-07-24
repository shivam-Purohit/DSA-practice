
#include <bits/stdc++.h>
using namespace std;

int find_min(int index, int curr_sum, int overall_sum, vector<int>& arr, int n, vector<vector<int>> &dp){

	if(index >= n){
		return INT_MAX;
	}
	// self calculated
	if(dp[index][curr_sum] != -1){
		return dp[index][curr_sum];
	}
	int right_sum  = overall_sum - curr_sum;

	int curr_diff = abs(right_sum - curr_sum);

	int min_picked = find_min(index+1, curr_sum+arr[index], overall_sum, arr, n, dp);

	int min_not_picked = find_min(index+1, curr_sum, overall_sum, arr, n, dp);
	dp[index][curr_sum] =  min(min_picked, min(min_not_picked, curr_diff));
	return dp[index][curr_sum];
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int overall_sum  = 0;
	for(auto i : arr){
		overall_sum += i;
	}
	vector<vector<int>> dp (n, vector<int>(overall_sum, -1));
	return find_min(0, 0, overall_sum, arr, n, dp);
}

