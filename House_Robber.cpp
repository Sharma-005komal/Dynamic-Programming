/*****House Robber Dynamic Programming*****/

#include <bits/stdc++.h>
using namespace std;


//Recursion Method
int func(int index, int a[])
{
    if(index == 0)
    {
        return a[index];
    }
    if(index < 0)
    {
        return 0;
    }
    int pick = a[index] + func(index - 2, a);
    int not_pick = 0 + func(index - 1, a);
    return max(pick, not_pick);
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    
    cout<<func(n-1, a)<<endl;

    return 0;
}


//Memoization Method
int func(int index, int a[], vector<int>& dp)
{
    if(index == 0)
    {
        return a[index];
    }
    if(index < 0)
    {
        return 0;
    }
    if(dp[index] != -1)
    {
        return dp[index];
    }
    int pick = a[index] + func(index - 2, a, dp);
    int not_pick = 0 + func(index - 1, a, dp);
    return dp[index] = max(pick, not_pick);
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    vector<int> dp(n, -1);
    
    cout<<func(n-1, a, dp)<<endl;

    return 0;
}


//Tabulation Method
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int dp[n];
    dp[0] = a[0];
    int neg = 0;
    
    for(int i=1; i<n; i++)
    {
        int take = a[i];
        if(i > 1)
        {
            take = take + dp[i-2];
        }
        int not_take = 0 + dp[i-1];
        dp[i] = max(take, not_take);
    }
    
    cout<<dp[n-1]<<endl;

    return 0;
}

//Space Optimization
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int prev = a[0];
    int prev2 = 0;
    
    for(int i=1; i<n; i++)
    {
        int take = a[i];
        if(i > 1)
        {
            take = take + prev2;
        }
        int not_take = 0 + prev;
        int cur_i = max(take, not_take);
        prev2 = prev;
        prev = cur_i;
    }
    
    cout<<prev<<endl;

    return 0;
}
