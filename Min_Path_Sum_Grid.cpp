/*****Minimum Path Sum in Grid in Dynamic Programming*****/

#include <bits/stdc++.h>
using namespace std;

//Recursion Method
int min_path(vector<vector<int>>& a, int i, int j)
{
    if(i==0 && j==0)
    {
        return a[0][0];
    }
    if(i<0 || j<0)
    {
        return 1e9;
    }
    int up = a[i][j] + min_path(a, i-1, j);
    int left = a[i][j] + min_path(a, i, j-1);
    return min(up, left);
}

int path_sum(vector<vector<int>>& a, int m, int n)
{
    return min_path(a, m-1, n-1);
}

int main()
{
    int m=3, n=3;
    vector<vector<int>> a{{10, 8, 2}, {10, 5, 100}, {1, 1, 2}};
  
    cout<<path_sum(a, m, n)<<endl;
    return 0;
}

//Memoization Method
int min_path(vector<vector<int>>& a, int i, int j, vector<vector<int>>& dp)
{
    if(i==0 && j==0)
    {
        return a[0][0];
    }
    if(i<0 || j<0)
    {
        return 1e9;
    }
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int up = a[i][j] + min_path(a, i-1, j, dp);
    int left = a[i][j] + min_path(a, i, j-1, dp);
    return dp[i][j] = min(up, left);
}

int path_sum(vector<vector<int>>& a, int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return min_path(a, m-1, n-1, dp);
}

int main()
{
    int m=3, n=3;
    vector<vector<int>> a{{10, 8, 2}, {10, 5, 100}, {1, 1, 2}};
  
    cout<<path_sum(a, m, n)<<endl;
    return 0;
}

//Tabulation Method
int main()
{
    int m=3, n=3;
    vector<vector<int>> a{{10, 8, 2}, {10, 5, 100}, {1, 1, 2}};
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==0 && j==0)
            {
                dp[i][j] = a[0][0];
            }
            else
            {
                int up = a[i][j];
                if(i>0)
                {
                    up += dp[i-1][j];
                }
                else
                {
                    up += 1e9;
                }
                int left = a[i][j];
                if(j>0)
                {
                    left += dp[i][j-1];
                }
                else
                {
                    left += 1e9;
                }
                dp[i][j] = min(up, left);
            }
        }
    }
    cout<<dp[m-1][n-1]<<endl;
    return 0;
}

//Space Optimization
int main()
{
    int m=3, n=3;
    vector<vector<int>> a{{10, 8, 2}, {10, 5, 100}, {1, 1, 2}};
    vector<int> prev(n, 0);
     for(int i=0; i<m; i++)
    {
        vector<int> curr(n, 0);
        for(int j=0; j<n; j++)
        {
            if(i==0 && j==0)
            {
                prev[i] = a[0][0];
            }
            else
            {
                int up = a[i][j];
                if(i>0)
                {
                    up += prev[j];
                }
                else
                {
                    up += 1e9;
                }
                int left = a[i][j];
                if(j>0)
                {
                    left += prev[j-1];
                }
                else
                {
                    left += 1e9;
                }
                curr[j] = min(up, left);
            }
        }
        prev = curr;
    }
    cout<<prev[n-1]<<endl;
    return 0;
}
