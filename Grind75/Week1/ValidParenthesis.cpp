#include <stack>
#include string.h;

using namespace std;

//Problem:

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 // Example 1:
// Input: s = "()"
// Output: true
// Example 2:
// Input: s = "()[]{}"
// Output: true
// Example 3:
// Input: s = "(]"
// Output: false
 
// Constraints:
// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

//intuition: we want to iterate through the string using every other character in the string starting with the first character
// then we can setup a series of cases which check if the next character is the correct closing bracket for the repective openning bracket that we have
// this seems like a brute force way to do it but its the first thing that came to my head
// if string length is odd then it will automatically ust be false as there is some opening parenthesis that is missing a closing one

class Solution {
public:
    bool isValid(string s) {

        if (s.length() % 2 == 0){
            return false; 
        }

        stack<char> openBrackets;

        for(char c : s.toCharArray()){
            if((c == '(') || (c == '[') || (c == '{')){
                openBrackets.push(c);
            }

            else if ((c == ')') || (c == ']') || (c == '}')){
                if(openBrackets.empty()){
                    return false; 
                }

                char openBracket = openBrackets.pop();
                if((c == '(' && openBracket != ')') || (c == '[' && openBracket != ']') ||  (c == '{' && openBracket != '}')){
                    return false; 
                }
                
            }
            
        }

        if (openBrackets.empty()){
            return true; 
        }

};
}