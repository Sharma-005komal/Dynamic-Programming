/*****Cherry Pickup in 3D Grid in Dynamic Programming*****/

#include <bits/stdc++.h>
using namespace std;

//Recursion Method
int func(vector<vector<int>>& a, int i, int j1, int j2, int r, int c)
{
    if(j1<0 || j1>=c || j2<0 || j2>c)
    {
        return -1e8;
    }
    if(i == r-1)
    {
        if(j1 == j2)
        {
            return a[i][j1];
        }
        else
        {
            return a[i][j1] + a[i][j2];
        }
    }
    int max_i = -1e8;
    for(int d1=-1; d1<=+1; d1++)
    {
        for(int d2=-1; d2<=+1; d2++)
        {
            if(j1 == j2)
            {
                max_i = max(max_i, (a[i][j1] + func(a, i+1, j1+d1, j2+d2, r, c)));
            }
            else
            {
                max_i = max(max_i, (a[i][j1] + a[i][j2] + func(a, i+1, j1+d1, j2+d2, r, c)));
            }
        }
    }
    return max_i;
}

int main()
{
    int r=3, c=4;
    vector<vector<int>> a{{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    cout<<func(a, 0, 0, c-1, r, c)<<endl;
    return 0;
}

//Memoization Method
int func(vector<vector<int>>& a, int i, int j1, int j2, int r, int c, vector<vector<vector<int>>>& dp)
{
    if(j1<0 || j1>=c || j2<0 || j2>=c)
    {
        return -1e8;
    }
    if(i == r-1)
    {
        if(j1 == j2)
        {
            return a[i][j1];
        }
        else
        {
            return a[i][j1] + a[i][j2];
        }
    }
    if(dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }
    int max_i = -1e8;
    for(int d1=-1; d1<=+1; d1++)
    {
        for(int d2=-1; d2<=+1; d2++)
        {
            int value = 0;
            if(j1 == j2)
            {
                value = a[i][j1];
            }
            else
            {
                value = a[i][j1] + a[i][j2];
            }
            value += func(a, i+1, j1+d1, j2+d2, r, c, dp);
            max_i = max(max_i, value);
        }
    }
    return max_i;
}

int main()
{
    int r=3, c=4;
    vector<vector<int>> a{{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    cout<<func(a, 0, 0, c-1, r, c, dp)<<endl;
    return 0;
}

//Tabulation Method
int main()
{
    int r=3, c=4;
    vector<vector<int>> a{{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));
    
    for(int j1=0; j1<c; j1++)
    {
        for(int j2=0; j2<c; j2++)
        {
            if(j1 == j2)
            {
                dp[r-1][j1][j2] = a[r-1][j1];
            }
            else
            {
                dp[r-1][j1][j2] = a[r-1][j1] + a[r-1][j2];
            }
        }
    }
    for(int i=r-2; i>=0; i--)
    {
        for(int j1=0; j1<c; j1++)
        {
            for(int j2=0; j2<c; j2++)
            {
                int max_i = -1e8;
                for(int d1=-1; d1<=+1; d1++)
                {
                    for(int d2=-1; d2<=+1; d2++)
                    {
                        int value = 0;
                        if(j1 == j2)
                        {
                           value = a[i][j1];
                        }
                        else
                        {
                            value = a[i][j1] + a[i][j2];
                        }
                        if(j1+d1>=0 && j1+d2<c && j2+d2>=0 && j2+d2<c)
                        {
                            value += dp[i+1][j1+d1][j2+d2];
                        }
                        else
                        {
                            value += -1e8;
                        }
                        max_i = max(max_i, value);
                    }
                }
                dp[i][j1][j2] = max_i;
            }
        }
    }
    
    cout<<dp[0][0][c-1]<<endl;
    
    return 0;
}
