class Solution {
public:
    int dp[501][2010];
    int maxSatisfaction(vector<int>& satisfaction)
    {
        sort(satisfaction.begin(), satisfaction.end());
        memset(dp, -1, sizeof(dp));
        return findAns(0, 1, satisfaction);
    }

    int findAns(int indx, int num, vector<int>& sat)
    {
        if (indx == sat.size())
            return 0;

        if (dp[indx][num] != -1)
            return dp[indx][num];
        int ans = 0;

        ans = max(sat[indx] * num + findAns(indx + 1, num + 1, sat), findAns(indx + 1, num, sat));

        return dp[indx][num] = ans;
    }
};