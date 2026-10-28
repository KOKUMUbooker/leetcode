#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>


/*
Given a string s, find the length of the longest substring without duplicate characters.
 
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int len {static_cast<int>(s.size())};

        int max {0};
        for (int i {0}; i < len; ++i)
        {
            std::unordered_map<char, bool> unique {};
            for (int j {i}; j < len; ++j)
            {
                if (unique.count(s[j]) != 0)
                    break;
                unique[s[j]] = true;
            }
            max = std::max(max , static_cast<int>(unique.size()));
        }

        return max;
    }
};

int main()
{
    Solution sln;
    std::string tst1 {"abcabcbb"};
    std::cout << tst1 << " : " << sln.lengthOfLongestSubstring(tst1) << " \n";

    std::string tst2 {"bbbbb"};
    std::cout << tst2 << " : " << sln.lengthOfLongestSubstring(tst2) << " \n";

    std::string tst3 {"pwwkew"};
    std::cout << tst3 << " : " << sln.lengthOfLongestSubstring(tst3) << " \n";

    return EXIT_SUCCESS;
}