#include <bits/stdc++.h>
using namespace std;

int find_max(int prev_ind, int day, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(day == 0){
        if(prev_ind == 0){
            return max(points[day][1], points[day][2]);
        }
        if(prev_ind == 1){
            return max(points[day][0], points[day][2]);
        }
        if(prev_ind == 2){
            return max(points[day][0], points[day][1]);
        }
    }
    if(dp[day][prev_ind] != -1){
        return dp[day][prev_ind];
    }

    int max1= 0;
    int max2 = 0;
    if(prev_ind==0){
        max1 = points[day][1] + find_max(1, day-1, points, dp);
        max2 = points[day][2] + find_max(2, day-1, points, dp);
    }
    if(prev_ind==1){
        max1 = points[day][0] + find_max(0, day-1, points, dp);
        max2 = points[day][2] + find_max(2, day-1, points, dp);
    }
    if(prev_ind==2){
        max1 = points[day][1] + find_max(1, day-1, points, dp);
        max2 = points[day][0] + find_max(0, day-1, points, dp);
    }
    dp[day][prev_ind] = max(max1, max2);
    return dp[day][prev_ind];
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp1(n, vector<int>(3, -1));
    vector<vector<int>> dp2(n, vector<int>(3, -1));
    vector<vector<int>> dp3(n, vector<int>(3, -1));
    int c1 = find_max(0, points.size()-1, points, dp1);
    int c2 = find_max(1, points.size()-1, points, dp2);
    int c3 = find_max(2, points.size()-1, points, dp3);
    return max(c1, max(c2, c3));

}