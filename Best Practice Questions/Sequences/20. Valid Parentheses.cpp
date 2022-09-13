/*
-----QUESTION-----
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/

//Runs in O(n) time 

class Solution {
public:
    bool isValid(string s) { //runs in O(n) time
        stack<char> brackets;
        char top; //top of stack
        
        for(int i = 0; i < s.length(); i++) {
            //open parentheses
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                brackets.push(s[i]); //add open bracket to stack
            } else {
                if(brackets.empty()) { //if stack is empty
                    return false;
                }

                top = brackets.top(); //get and remove top of stack
                brackets.pop();

                //close brackets
                if(s[i] != '}' && top == '{') {
                    return false;
                }
                if(s[i] != ']' && top == '[') {
                    return false;
                }
                if(s[i] != ')' && top == '(') {
                    return false;
                }
            }
        }
            
        if(brackets.size() != 0) { //if extra brackets
            return false;
        }
        return true;
    }
};