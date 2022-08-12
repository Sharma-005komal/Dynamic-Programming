/*****Frog Jump DP*****/

#include <bits/stdc++.h>
using namespace std;

//Recursion Method

int func(int index, int a[])
{
    if(index == 0)
    {
        return 0;
    }
    int left = func(index-1, a) + abs(a[index] - a[index-1]);
    int right = INT_MAX;
    if(index > 1)
    {
        right = func(index-2, a) + abs(a[index] - a[index-2]);
    }
    return min(left, right);
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
        return 0;
    }
    if(dp[index] != -1)
    {
        return dp[index];
    }
    int left = func(index-1, a, dp) + abs(a[index] - a[index-1]);
    int right = INT_MAX;
    if(index > 1)
    {
        right = func(index-2, a, dp) + abs(a[index] - a[index-2]);
    }
    return dp[index] = min(left, right);
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
    vector<int> dp(n+1, -1);
    
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
    vector<int> dp(n+1, 0);
    dp[0] = 0;
    
    for(int i=1; i<n; i++)
    {
        int first = dp[i-1] + abs(a[i] - a[i-1]);
        int second = INT_MAX;
        if(i>1)
        {
            second = dp[i-2] + abs(a[i] - a[i-2]);
        }
        dp[i] = min(first, second);
    }
    
    cout<<dp[n-1]<<endl;
    
    return 0;
}


//Optimization Space 

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int prev = 0, prev2 = 0;
    
    for(int i=1; i<n; i++)
    {
        int first = prev + abs(a[i] - a[i-1]);
        int second = INT_MAX;
        if(i>1)
        {
            second = prev2 + abs(a[i] - a[i-2]);
        }
        int curi = min(first, second);
        prev2 = prev;
        prev = curi;
    }
    
    cout<<prev<<endl;
    
    return 0;
}

