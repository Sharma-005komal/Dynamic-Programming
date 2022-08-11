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
