/*****Climbing Stairs DP*****/

#include <bits/stdc++.h>
using namespace std;

//Recursion Method
int func(int ind)
{
    if(ind == 0)
    {
        return 1;
    }
    if(ind == 1)
    {
        return 1;
    }
    int left = func(ind - 1);
    int right = func(ind - 2);
    return left + right;
}

int main()
{
    int n;
    cin>>n;
    
    cout<<func(n)<<endl;

    return 0;
}


//Memoization Method

int func(int ind, vector<int>& dp1, vector<int>& dp2)
{
    if(ind == 0)
    {
        return 1;
    }
    if(ind == 1)
    {
        return 1;
    }
    if(dp1[ind] != -1)
    {
        return dp1[ind];
    }
    if(dp2[ind] != -1)
    {
        return dp2[ind];
    }
    int left = func(ind - 1, dp1, dp2);
    int right = func(ind - 2, dp1, dp2);
    return left + right;
}

int main()
{
    int n;
    cin>>n;
    vector<int> dp1(n+1, -1);
    vector<int> dp2(n+1, -1);
    
    cout<<func(n, dp1, dp2)<<endl;

    return 0;
}

//Tabulation Method

int main()
{
    int n;
    cin>>n;
    int dp[n+1];
    dp[0] = 1, dp[1] = 1;
    
    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    cout<<dp[n]<<endl;

    return 0;
}


//Optimization Space 

int main()
{
    int n;
    cin>>n;
    
    int prev = 1, prev2 = 1;
    
    for(int i=2; i<=n; i++)
    {
        int curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    }
    
    cout<<prev<<endl;

    return 0;
}
