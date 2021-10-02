class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
            return false;
        int s1_fre[26];
        memset(s1_fre, 0, sizeof s1_fre);
        for (auto i : s1)
            s1_fre[i - 'a']++;
        for (int i = 0; i <= s2.size() - s1.size(); i++) {
            int s2_fre[26];
            memset(s2_fre, 0, sizeof s2_fre);
            for (int j = 0; j < s1.size(); j++) {
                s2_fre[s2[j + i] - 'a']++;
            }
            if (matches(s1_fre, s2_fre))
                return true;
        }
        return false;
    }

    bool matches(int s1[26], int s2[26])
    {
        for (int i = 0; i < 26; i++)
            if (s1[i] != s2[i])
                return false;
        return true;
    }
};