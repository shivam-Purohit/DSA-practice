#include <bits/stdc++.h> 
using namespace std;

long find_count(int index, int target, int *num, vector<vector<long>> &dp){
    if(index==0){
        if((target % num[index]) == 0){
            return 1;
        }
        else{
            return 0;
        }

    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    long pick = 0;
    if(target >= num[index]){
        // pick is possible
        pick =  find_count(index, target-num[index], num, dp);
    }
    long notpick = find_count(index-1, target, num, dp);

     return dp[index][target] = pick+notpick;

}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n+1, vector<long>(value+1, -1));
    return find_count(n-1, value, denominations, dp);
}