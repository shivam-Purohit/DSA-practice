#include <bits/stdc++.h>
using namespace std;

    int find_com(int index1, int index2, string &str1, string &str2, vector<vector<int>>& dp){
        if(index1< 0 or index2 <0 ){
            return 0;
        }

        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }
        if(str1[index1] == str2[index2]){
            return dp[index1][index2] = 1+ find_com(index1-1, index2-1, str1, str2, dp);
        }

        return dp[index1][index2] = max(find_com(index1-1, index2, str1, str2, dp), find_com(index1, index2-1, str1, str2, dp));
    }

int canYouMake(string &s1, string &s2){
    // Write your code here.
    int size1 = s1.size();
    int size2 = s2.size();
    vector<vector<int>> dp(size1+1, vector<int>(size2+1, -1));

    return (size1 + size2 - 2*find_com(size1-1, size2-1, s1, s2, dp));
}