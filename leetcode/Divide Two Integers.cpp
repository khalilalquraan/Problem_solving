/*
    Problem Url : https://leetcode.com/problems/divide-two-integers/
    Date : 03-07-2021
*/
class Solution {
public:
    int divide(int dividend, int divisor)
    {
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

        dividend = abs(dividend);
        divisor = abs(divisor);

        long long ans = 0, tmp = 0;

        for (int i = 31; i >= 0; i--) {
            if (tmp + (1LL * divisor << i) <= dividend) {
                tmp += (1LL * divisor << i);
                ans |= (1LL << i);
            }
        }
        return min(1LL * ans * sign, 1LL * INT_MAX);
    }
};  