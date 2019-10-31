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
        string result; //converted string to be returned
        int skipLines; //number of lines that need to be skipped
        int curr = 0; //current index of the string
        
        //checks is number of rows if even or not
        if(numRows%2 == 0) { 
            skipLines = numRows + 2;
        } else {
            skipLines = numRows + 1;
        }
        
        for(int i = 0; i < s.size(); i++) {
            result = result + s[curr];
            curr = curr + skipLines; 
            if(skipLines > s.size()){
                curr = curr%(s.size() - 1);
            }
        }
        
        return result;
        
    }
};