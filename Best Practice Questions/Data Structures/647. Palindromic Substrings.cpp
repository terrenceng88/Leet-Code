/*
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.
*/


//Runs in O(n^2) complexity using mathematical solution (triangular numbers)

class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size(); 
        int palindromes = 0; //number of palindrome substrings
        
        for(int mid = 0; mid < len; mid++) {
            int left = mid - 1; //left pointer to find left edge of palindrome
            int right = mid; //right pointer to find right edge of palindrome
            
            //identify how long is the center of the palindrome (could be 2 for even number lengthed substrings, 1 for odd) while checking for duplicate characters
            while(right < len-1 && s[right] == s[right + 1]) { //move right pointer up until it reaches end of non repeating numbers or the end of the string
                right++; 
            }
            
            //nth triangula number
            //center is no longer just a single palindrome, it will be the Nth triangular number (defined as N*(N+1)/2) to account for all the smaller palindromes of which it's made
            int trilen = right - left; //get N for Nth triangular number formula (length between left and right pointers)
            palindromes = palindromes + (trilen * (trilen + 1))/2; //get the Nth triangular number and add it to the current count of palindrome substrings
            mid = right; //current right is one step more ahead than center
            right++; //move right to the non repeating number
            
            //check palindrome
            while(left >= 0 && right < len && s[right] == s[left]) { //check how many palindromes inside the larger palindrome
                right++; //spread to the right
                left--; //spread to the left
                palindromes++; 
            }
        }
        
        return palindromes;
    }
};
