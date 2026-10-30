#include <cstdlib>
#include <ios>
#include <string>
#include <array>
#include <iostream>

/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false
*/

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if (s2.size() < s1.size())
            return false;

        std::array<int, 26> s1Count{};
        std::array<int, 26> windowCount{};

        int len = static_cast<int>(s1.size());

        // Count characters in s1 and the first window of s2.
        for (int i = 0; i < len; ++i) {
            ++s1Count[s1[i] - 'a'];
            ++windowCount[s2[i] - 'a'];
        }

        // Check the first window.
        if (s1Count == windowCount)
            return true;

        // Slide the window one character at a time.
        for (int r = len; r < static_cast<int>(s2.size()); ++r) {
            // Add the new character entering the window.
            ++windowCount[s2[r] - 'a'];

            // Remove the character leaving the window.
            --windowCount[s2[r - len] - 'a'];

            if (s1Count == windowCount)
                return true;
        }

        return false;
    }
};

int main() {
    std::cout << std::boolalpha;

    Solution sln;

    std::string s1a{"ab"};
    std::string s2a{"eidbaooo"};
    std::cout << sln.checkInclusion(s1a, s2a) << '\n'; // true

    std::string s1b{"ab"};
    std::string s2b{"eidboaoo"};
    std::cout << sln.checkInclusion(s1b, s2b) << '\n'; // false

    std::string s1c{"ab"};
    std::string s2c{"aab"};
    std::cout << sln.checkInclusion(s1c, s2c) << '\n'; // true

    return EXIT_SUCCESS;
}