/*****Triangle in Grid Dynamic Programming*****/

#include <bits/stdc++.h>
using namespace std;

//Recursion Method
int func_rec(vector<vector<int>>& t, int i, int j, int n)
{
    if(i == n-1)
    {
        return t[n-1][j];
    }
    int down = t[i][j] + func_rec(t, i+1, j, n);
    int dg = t[i][j] + func_rec(t, i+1, j+1, n);
    return min(down, dg);
}

int func(vector<vector<int>>& t, int n)
{
    return func_rec(t, 0, 0, n);
}

int main()
{
    int n=4;
    vector<vector<int>> triangle{{1}, {2,3}, {3,6,7}, {8,9,6,10}};
    cout<<func(triangle, n)<<endl;
    return 0;
}

//Memoization Method
int func_rec(vector<vector<int>>& t, int i, int j, int n, vector<vector<int>>& dp)
{
    if(i == n-1)
    {
        return t[n-1][j];
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int down = t[i][j] + func_rec(t, i+1, j, n, dp);
    int dg = t[i][j] + func_rec(t, i+1, j+1, n, dp);
    return dp[i][j] = min(down, dg);
}

int func(vector<vector<int>>& t, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return func_rec(t, 0, 0, n, dp);
}

int main()
{
    int n=4;
    vector<vector<int>> triangle{{1}, {2,3}, {3,6,7}, {8,9,6,10}};
    cout<<func(triangle, n)<<endl;
    return 0;
}

//Tabulation Method
int main()
{
    int n=4;
    vector<vector<int>> t{{1}, {2,3}, {3,6,7}, {8,9,6,10}};
    int dp[n][n];
    for(int j=0; j<n; j++)
    {
        dp[n-1][j] = t[n-1][j];
    }
    for(int i=2; i>=0; i--)
    {
        for(int j=i; j>=0; j--)
        {
            int down = t[i][j] + dp[i+1][j];
            int dg = t[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, dg);
        }
    }
    
    cout<<dp[0][0]<<endl;
    return 0;
}

//Space Optimization
int main()
{
    int n=4;
    vector<vector<int>> t{{1}, {2,3}, {3,6,7}, {8,9,6,10}};
    vector<int> prev(n, 0);
    for(int j=0; j<n; j++)
    {
        prev[j] = t[n-1][j];
    }
    for(int i=2; i>=0; i--)
    {
        vector<int> curr(n, 0);
        for(int j=i; j>=0; j--)
        {
            int down = t[i][j] + prev[j];
            int dg = t[i][j] + prev[j+1];
            curr[j] = min(down, dg);
        }
        prev = curr;
    }
    
    cout<<prev[0]<<endl;
    return 0;
}
