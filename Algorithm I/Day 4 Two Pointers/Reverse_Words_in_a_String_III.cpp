class Solution {
public:
    string reverseWords(string s)
    {
        string ans = "";
        string tmp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ' || i == s.size() - 1) {
                if (i == s.size() - 1)
                    tmp += s[i];
                reverse(tmp.begin(), tmp.end());
                ans += tmp + (i == s.size() - 1 ? "" : " ");
                tmp = "";
            }
            else
                tmp += s[i];
        }
        return ans;
    }
};