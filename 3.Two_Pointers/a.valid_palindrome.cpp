#include <cstdlib>
#include <ios>
#include <string>
#include <cctype> 
#include <iostream>

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