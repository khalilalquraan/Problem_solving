/*
    Problem Url : https://leetcode.com/problems/longest-palindromic-substring/
    Date : 2021-06-27
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int len = 1;
        int ansl = 0 , ansr = 0;
        for(int i = 0 ; i < n ; i++) {
            int l = i - 1 , r = i + 1;
            while(l >= 0 && r < n) {
                if(s[l] == s[r]) {
                    if(len < r - l + 1) {
                        len = r - l + 1;
                        ansl = l;
                        ansr = r;
                    }
                    l--;
                    r++;
                } else {
                    break;
                }
            }
            l = i , r = i + 1;
            while(l >= 0 && r < n) {
                if(s[l] == s[r]) {
                    if(len < r - l + 1) {
                        len = r - l + 1;
                        ansl = l;
                        ansr = r;
                    }
                    l--;
                    r++;
                } else {
                    break;
                }
            }
        }
        return s.substr(ansl,len);
    }
};