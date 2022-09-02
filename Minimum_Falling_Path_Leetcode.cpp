class Solution {
public:
    int func(vector<vector<int>>& m, int i, int j, int n)
    {
        //Before destination condition
        if(j<0 || j>=n)
        {
            return 1e9;
        }
        //Out of bound condition
        if(i == 0)
        {
            return m[0][j];
        }
        
        int s = m[i][j] + func(m, i-1, j, n);
        int l = m[i][j] + func(m, i-1, j-1, n);
        int r = m[i][j] + func(m, i-1, j+1, n);
        return min(s, min(l, r));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //Recursion Method
        int n = matrix.size();
        int result = 1e9;
        for(int i=0; i<n; i++)
        {
            int temp = func(matrix, n-1, i, n);
            result = min(result, temp);
        }
        return result;
    }
};

class Solution {
public:
    int func(vector<vector<int>>& m, int i, int j, int n, vector<vector<int>>& dp)
    {
        //Before destination condition
        if(j<0 || j>=n)
        {
            return 1e9;
        }
        //Out of bound condition
        if(i == 0)
        {
            return m[0][j];
        }
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int s = m[i][j] + func(m, i-1, j, n, dp);
        int l = m[i][j] + func(m, i-1, j-1, n, dp);
        int r = m[i][j] + func(m, i-1, j+1, n, dp);
        return dp[i][j] = min(s, min(l, r));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //Memoization Method
        int n = matrix.size();
        int result = 1e9;
        for(int i=0; i<n; i++)
        {
            vector<vector<int>> dp(n, vector<int>(n, -1));
            int temp = func(matrix, n-1, i, n, dp);
            result = min(result, temp);
        }
        return result;
    }
};

