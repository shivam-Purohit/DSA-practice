#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

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
    int longestPalindromeSubseq(string s) {
        string revS = s;

        int first = 0;
        int last = revS.size()-1;

        while(first < last){
            char temp = revS[first];
            revS[first] = revS[last];
            revS[last] = temp;

            first ++;
            last --;
        }
        int size1 = s.size();
        int size2 = revS.size();

        vector<vector<int>> dp(size1+1, vector<int>(size2+1, -1));
        return find_com(size1-1, size2-1, s, revS, dp);
    }
};