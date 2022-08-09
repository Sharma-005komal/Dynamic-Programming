/*****Recursion Method*****/

#include <bits/stdc++.h>
using namespace std;

int fun(int n)
{
    if(n <= 1)
    {
        return n;
    }
    
    return fun(n-1) + fun(n-2); 
}

int main()
{
    int n;
    cin>>n;
    
    cout<<fun(n)<<endl;
    
    return 0;
}


/*****Memoization Method*****/

int fun(int n, vector<int>& dp)
{
    if(n <= 1)
    {
        return n;
    }
    
    if(dp[n] != -1)
    {
        return dp[n];
    }
    
    return dp[n] = fun(n-1, dp) + fun(n-2, dp); 
}

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1, -1);
    
    cout<<fun(n, dp)<<endl;
    
    return 0;
}

/*****Tabulation Method*****/

int main()
{
    int n;
    cin>>n;
    int dp[n+1];
    
    dp[0] = 0, dp[1] = 1;
    
    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    cout<<dp[n]<<endl;
    
    return 0;
}

/*****Optimization Code*****/

int main()
{
    int n;
    cin>>n;
    
    int prev2 = 0, prev = 1;
    
    for(int i=2; i<=n; i++)
    {
        int curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    }
    
    cout<<prev<<endl;
    
    return 0;
}
