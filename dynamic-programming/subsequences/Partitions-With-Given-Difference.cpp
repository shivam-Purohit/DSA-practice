#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int findcount(int index, int sum, int target, vector<vector<int>>& dp, vector<int>& arr, int n) {
    if(index == n) {
        return sum == target ? 1 : 0;
    }

    if(dp[index][sum] != -1) {
        return dp[index][sum];
    }

    int pick = 0;
    if(sum + arr[index] <= target)
        pick = findcount(index + 1, sum + arr[index], target, dp, arr, n);

    int notpick = findcount(index + 1, sum, target, dp, arr, n);

    return dp[index][sum] = (pick + notpick) % mod;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    if ((totalSum + d) % 2 != 0 || totalSum < d)
        return 0;

    int target = (totalSum + d) / 2;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

    return findcount(0, 0, target, dp, arr, n);
}
