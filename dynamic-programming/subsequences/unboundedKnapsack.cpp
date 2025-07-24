#include <bits/stdc++.h> 
using namespace std;

int find_max_value(int index, int rem_wt, vector<int> &v, vector<int> &w, vector<vector<int>>&dp){
    if(index==0){
        if(rem_wt == w[0]){
            return v[0];
        }
        if(rem_wt > w[0]){
            return( (rem_wt / w[0]) * v[0]);
        }
        return 0;
    }
    if(dp[index][rem_wt] != -1){
        return dp[index][rem_wt];
    }

    int pick = 0;
    if(rem_wt >= w[index]){
        // we can pick
        pick = v[index] + find_max_value(index, rem_wt-w[index], v, w, dp);
    }

    int notpick = find_max_value(index-1, rem_wt, v, w, dp);

    return dp[index][rem_wt] = max(pick, notpick);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
     vector<vector<int>> dp (n+1, vector<int>(w+1, -1));
    return find_max_value(n-1, w, profit, weight, dp);
}