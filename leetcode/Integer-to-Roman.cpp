/*

    Problem Url : https://leetcode.com/problems/integer-to-roman/
    Date : 29/06/2021

*/
class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        ans += charRep('M' , num / 1000) + ((num % 1000 >= 900) ? "CM" : "");
        num %= 1000; num %= 900;
        ans += charRep('D' , num / 500) + ((num % 500 >= 400) ? "CD" : "");
        num %= 500; num %= 400;
        ans += charRep('C' , num / 100) + ((num % 100 >= 90) ? "XC" : "");
        num %= 100; num %= 90;
        ans += charRep('L' , num / 50) + ((num % 50 >= 40) ? "XL" : "");
        num %= 50; num %= 40;
        ans += charRep('X' , num / 10) + ((num % 10 >= 9) ? "IX" : "");
        num %= 10; num %= 9;
        ans += charRep('V' , num / 5) + ((num % 5 >= 4) ? "IV" : "");
        num %= 5; num %= 4;
        ans += charRep('I' , num);
        return ans;
        
    }
    string charRep(char c,int r) {
        string ans = "";
        for(int i = 0 ; i < r ; i++) {
            ans += c;
        }
        return ans;
    }
};