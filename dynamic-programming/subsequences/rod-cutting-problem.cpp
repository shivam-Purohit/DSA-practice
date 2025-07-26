#include <bits/stdc++.h> 
using namespace std;
int find_max(int rem_len, vector<int> &price, vector<int> &dp){
	if(rem_len==0){
		return 0;
	}
	int max_cost = 0;
	if(dp[rem_len] != -1){
		return dp[rem_len];
	}
	for(int i = 1; i <=rem_len;i++){
		int curr_cut_cost = price[i-1] + find_max(rem_len-i, price, dp);
		max_cost = max(max_cost, curr_cut_cost);
	}
	return dp[rem_len]= max_cost;
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int> dp(n+1, -1);
	return find_max(n, price, dp);
}
