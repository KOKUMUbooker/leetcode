#include <cstdlib>
#include <ios>
#include <string>
#include <cctype> 
#include <iostream>

/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/

class Solution {
private:
    inline bool IsAlphaNum(char ch)
    {
        return (ch >= 'a' && ch <= 'z') || 
           (ch >= 'A' && ch <= 'Z') || 
           (ch >= '0' && ch <= '9');
    }

public:
    bool isPalindrome(std::string s) {
        std::string normalized {""};
        for (char& c : s)
        {
            if (IsAlphaNum(c))
                normalized += std::tolower(c);
        }

        std::string rev {""};
        int len {static_cast<int>(normalized.size())};
        for (int i {len-1}; i >= 0; --i)
            rev += normalized[i];

        return normalized == rev;
    }
};

int main()
{
    Solution sln;
    std::cout << std::boolalpha;

    std::cout << sln.isPalindrome(std::string("A man, a plan, a canal: Panama")) << "\n";
    std::cout << sln.isPalindrome(std::string("race a car")) << "\n";
    std::cout << sln.isPalindrome(std::string(" ")) << "\n";

    return EXIT_SUCCESS;
}