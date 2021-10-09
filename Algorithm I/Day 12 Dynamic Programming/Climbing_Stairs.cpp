class Solution {
public:
    int dp[50][50];
    int climbStairs(int n)
    {
        memset(dp, -1, sizeof(dp));
        return calc(0, n);
    }
    int calc(int i, int n)
    {
        if (i > n)
            return 0;

        if (i == n)
            return 1;

        if (dp[i][n] != -1)
            return dp[i][n];

        int ans = calc(i + 1, n) + calc(i + 2, n);

        return dp[i][n] = ans;
    }
};

/*
 
 n = 5 
 
 1 1 1 1 1 -> 1
 1 1 1 2 -> 4
 1 2 2 -> 3
 

*/