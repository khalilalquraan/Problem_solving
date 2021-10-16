class Solution {
public:
    bool backspaceCompare(string s, string t)
    {

        int f = 0;
        int ss = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#' && f > 0)
                f--;
            else if (s[i] != '#') {
                s[f] = s[i];
                f++;
            }
        }

        for (int i = 0; i < t.size(); i++) {
            if (t[i] == '#' && ss > 0)
                ss--;
            else if (t[i] != '#') {
                t[ss] = t[i];
                ss++;
            }
        }

        if (ss != f)
            return false;
        for (int i = 0; i < f; i++)
            if (t[i] != s[i])
                return false;
        return true;
    }
};