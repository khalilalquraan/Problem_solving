/*
    Problem Url : https://leetcode.com/problems/count-and-say
    Date : 2021-07-06
*/
class Solution {
public:
    string countAndSay(int n)
    {
        string res = "1";
        n--;
        while (n--) {
            res = countString(res);
        }
        return res;
    }
    string countString(string s)
    {
        int counter = 0;
        char d = ' ';
        string ans = "";

        for (auto i : s) {
            if (i == d) {
                counter++;
            }
            else {
                if (counter != 0) {
                    ans += to_string(counter) + d;
                }
                d = i;
                counter = 1;
            }
        }
        ans += to_string(counter) + d;
        return ans;
    }
};