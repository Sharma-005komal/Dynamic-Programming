/*****Grid Unique Path in Dynamic Programming*****/

#include <bits/stdc++.h>
using namespace std;

//Recursion Method
int func(vector<vector<int>>& a, int i, int j)
{
    if(i>=0 && j>=0 && a[i][j]==1)    //Dead Cell return nothing
    {
        return 0;
    }
    if(i==0 && j==0)      //Valid cell counts
    {
        return 1;
    }
    if(i<0 || j<0)       //Out of bound conditions
    {
        return 0;
    }
    
    int up = func(a, i-1, j);
    int left = func(a, i, j-1);
    return (up+left);
}

int path(vector<vector<int>>& a, int i, int j)
{
    return func(a, i-1, j-1);
}

int main()
{
    int m=3, n=3;

    vector<vector<int>> a{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    
    cout<<path(a, m, n)<<endl;
    return 0;
}

//Mempization Method
int func(vector<vector<int>>& a, int i, int j, vector<vector<int>>& dp)
{
    if(i>=0 && j>=0 && a[i][j]==1)    //Dead Cell return nothing
    {
        return 0;
    }
    if(i==0 && j==0)      //Valid cell counts
    {
        return 1;
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if(i<0 || j<0)       //Out of bound conditions
    {
        return 0;
    }
    
    int up = func(a, i-1, j, dp);
    int left = func(a, i, j-1, dp);
    return dp[i][j] = (up+left);
}

int path(vector<vector<int>>& a, int i, int j, vector<vector<int>>& dp)
{
    return func(a, i-1, j-1, dp);
}

int main()
{
    int m=3, n=3;

    vector<vector<int>> a{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout<<path(a, m, n, dp)<<endl;
    
    return 0;
}
