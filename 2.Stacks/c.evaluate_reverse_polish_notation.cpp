#include <cstdlib>
#include <vector>
#include <stack>
#include <string>
#include <iostream>

/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
Evaluate the expression. Return an integer that represents the value of the expression.

Note that:
    The valid operators are '+', '-', '*', and '/'.
    Each operand may be an integer or another expression.
    The division between two integers always truncates toward zero.
    There will not be any division by zero.
    The input represents a valid arithmetic expression in a reverse polish notation.
    The answer and all the intermediate calculations can be represented in a 32-bit integer.

Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/

class Solution {
private:
    inline bool IsOperator(const std::string& s)
    {
        return s == "+" || s == "-" || s == "*" || s == "/";
    }
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stack;
        
        for (const std::string& s : tokens)
        {
            if (!IsOperator(s))
            {
                int n {std::stoi(s)};
                stack.push(n);
            }
            else
            {
                if (stack.size() < 2)
                    return 0;
                int res {0};
                int b {stack.top()};
                stack.pop();
                int a {stack.top()};
                stack.pop();
                if (s == "+")
                    res = a + b;
                else if (s == "-")
                    res = a - b;
                else if (s == "/")
                    res = a / b;
                else if (s == "*")
                    res = a * b;
                else 
                    continue;

                stack.push(res);
            }
        }

        if (stack.size() != 1)
            return 0;
        else 
            return stack.top();
    }
};

int main()
{
    Solution sln;
    std::vector<std::string> tst1 {"2","1","+","3","*"};
    std::cout << "Test 1 : " << sln.evalRPN(tst1) << "\n";

    std::vector<std::string> tst2 {"4","13","5","/","+"};
    std::cout << "Test 2 : " << sln.evalRPN(tst2) << "\n";

    std::vector<std::string> tst3 {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    std::cout << "Test 3 : " << sln.evalRPN(tst3) << "\n";

    return EXIT_SUCCESS;
}