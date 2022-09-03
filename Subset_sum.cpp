/*****Subset Sum Equal To Target in Dynamic Programming*****/

#include <bits/stdc++.h>
using namespace std;

//Recursion Method
bool func(vector<int>& a, int index, int target)
{
    if(target == 0)
    {
        return true;
    }
    if(index == 0)
    {
        return (a[0] == target);
    }
    bool not_take = func(a, index-1, target);
    bool take = false;
    if(target >= a[index])
    {
        take = func(a, index-1, target-a[index]);
    }
    return take | not_take;
}

int main()
{
    int n, k;
    cin>>n;
    vector<int> a;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    cin>>k;
    cout<<func(a, n-1, k)<<endl;
    return 0;
}

//Memoization Method
bool func(vector<int>& a, int index, int target, vector<vector<int>>& dp)
{
    if(target == 0)
    {
        return true;
    }
    if(index == 0)
    {
        return (a[0] == target);
    }
    if(dp[index][target] != -1)
    {
        return dp[index][target];
    }
    bool not_take = func(a, index-1, target, dp);
    bool take = false;
    if(target >= a[index])
    {
        take = func(a, index-1, target-a[index], dp);
    }
    return dp[index][target] = take | not_take;
}

int main()
{
    int n, k;
    cin>>n;
    vector<int> a;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    cin>>k;
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    cout<<func(a, n-1, k, dp)<<endl;
    return 0;
}

//Tabulation Method
int main()
{
    int n, k;
    cin>>n;
    vector<int> a;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    cin>>k;
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));
    for(int i=0; i<n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][a[0]] = true;
    for(int index=1; index<n; index++)
    {
        for(int target=1; target<=k; target++)
        {
            bool not_take = dp[index-1][target];
            bool take = false;
            if(target >= a[index])
           {
               take = dp[index-1][target-a[index]];
           }
           dp[index][target] = take | not_take;
        }
    }
    cout<<dp[n-1][k]<<endl;
    return 0;
}

//Space Optimization
int main()
{
    int n, k;
    cin>>n;
    vector<int> a;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    cin>>k;
    vector<bool> prev(k+1, 0), cur(k+1, 0);
    prev[0] = cur[0] = true;
    prev[a[0]] = true;
    for(int index=1; index<n; index++)
    {
        for(int target=1; target<=k; target++)
        {
            bool not_take = prev[target];
            bool take = false;
            if(target >= a[index])
           {
               take = prev[target-a[index]];
           }
           cur[target] = take | not_take;
        }
        prev = cur;
    }
    cout<<prev[k]<<endl;
    return 0;
}
