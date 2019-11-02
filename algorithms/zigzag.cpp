/*----------------------- Question -----------------------*/
/* 
Share
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/

/*----------------------- Solution -----------------------*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) { //edge case for one row, cant zig zag
            return s;
        }
        
        string result = ""; //converted string to be returned
        int skipLines = 2 * (numRows - 1); //number of max chars that need to be skipped
        int rowSkip;  //number of chars that need to be skipped in a row
        int curr; //current index of the string

        for(int i = 0; i < numRows; ++i) { //iterates through each row
           curr = i; //current char set to row # in row
           rowSkip = skipLines - (2 * i); 

            while(curr < s.size()) { //while still in current zigzag row                
                if(rowSkip == 0) { //if rowSkip is 0, set it to max char skip
                    rowSkip = skipLines;
                }

                result = result + s[curr];
                curr = curr + rowSkip;
                rowSkip = skipLines - rowSkip;
            }

        }

        return result;
    
    }
};