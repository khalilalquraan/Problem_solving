/*
    
    problem Url : https://leetcode.com/problems/zigzag-conversion/
    Date : 28-06-2021

*/

class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1) return s;
        
        vector<string> row( min( numRows , (int)s.size() ) );
        int curRow = 0;
        bool goingDown = false;
        
        for(auto c : s) {
            row[curRow]+=c;
            if(curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            
            curRow += goingDown ? 1 : -1;
        }
        string ans = "";
        for(auto r : row) ans += r;
        return ans;
    }
};