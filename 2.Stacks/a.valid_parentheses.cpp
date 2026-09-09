#include <cstdlib>
#include <ios>
#include <string>
#include <stack>
#include <unordered_map>
#include <iostream>

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true

Example 5:
Input: s = "([)]"
Output: false
*/

class Solution {
public:
    bool isValid(std::string s) {
        std::unordered_map<char,char> bracketMap {
           { ')','('},
           { '}','{'},
           { ']','['},
        };

        std::stack<char> bracketStack;
        for (char& c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                bracketStack.push(c);
                continue;
            }
            
            if (c == ')' || c == '}' || c == ']')
            {
                if (bracketStack.size() == 0)
                    return false;

                if (bracketMap[c] == bracketStack.top())
                    bracketStack.pop();
                else 
                    return false;
            }
        }

        return bracketStack.size() == 0;
    }   
};

int main()
{
    Solution sln;
    std::cout << std::boolalpha;
    std::cout << "()     -> " << sln.isValid("()") << "\n";
    std::cout << "()[]{} -> " << sln.isValid("()[]{}") << "\n";
    std::cout << "(]     -> " << sln.isValid("(]") << "\n";
    std::cout << "([])   -> " << sln.isValid("([])") << "\n";
    std::cout << "([)]   -> " << sln.isValid("([)]") << "\n";

    return EXIT_SUCCESS;
}