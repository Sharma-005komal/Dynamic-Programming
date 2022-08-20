/*****Grid Unique Path Dynamic Programming*****/

#include <bits/stdc++.h>
using namespace std;

//Recursion Method
int func(int i, int j)
{
    if(i==0 && j==0)
    {
        return 1;
    }
    if(i<0 || j<0)
    {
        return 0;
    }
    int up = func(i-1, j);
    int left = func(i, j-1);
    return (up + left);
}

int main()
{
    int m, n;
    cin>>m>>n;
    
    cout<<func(m-1, n-1)<<endl;

    return 0;
}

//Memoization Method
int func(int i, int j, vector<vector<int>>& dp)
{
    if(i==0 && j==0)
    {
        return 1;
    }
    if(i<0 || j<0)
    {
        return 0;
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int up = func(i-1, j, dp);
    int left = func(i, j-1, dp);
    return dp[i][j] = up + left;
}

int main()
{
    int m, n;
    cin>>m>>n;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout<<func(m-1, n-1, dp)<<endl;

    return 0;
}

//Tabulation Method
int main()
{
    int m, n;
    cin>>m>>n;
    int dp[m][n];
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0 && j==0)
            {
                dp[0][0] = 1;
            }
            else
            {
                int up = 0, left = 0;
                if(i > 0)
                {
                    up = dp[i-1][j];
                }
                if(j > 0)
                {
                    left = dp[i][j-1];
                }
                dp[i][j] = up + left;
            }
        }
    }
    cout<<dp[m-1][n-1]<<endl;
    return 0;
}

//Space Optimization
int main()
{
    int m, n;
    cin>>m>>n;
    vector<int> prev(n, 0);
    for(int i=0; i<m; i++)
    {
        vector<int> temp(n, 0);
        for(int j=0; j<n; j++)
        {
            if(i==0 && j==0)
            {
                prev[j] = 1;
            }
            else
            {
                temp[j] = prev[j] + temp[j-1];
            }
        }
        prev = temp;
    }
    cout<<prev[n-1]<<endl;
    
    return 0;
}
