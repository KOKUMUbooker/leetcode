#include <iostream>
#include <unordered_map>
#include <string>

/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
*/

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size())
            return false;

        std::unordered_map<char,int> sCharMap {};
        std::unordered_map<char,int> tCharMap {};

        int len {static_cast<int>(s.size())};
        for(int i {0}; i < len; ++i)
        {
            char sChar {s[i]};
            char tChar {t[i]};

            if (sCharMap.count(sChar) > 0)
               ++sCharMap[sChar]; 
            else
                sCharMap.try_emplace(sChar,1);

            if (tCharMap.count(tChar) > 0)
               ++tCharMap[tChar]; 
            else
                tCharMap.try_emplace(tChar,1);
        }

        for (std::pair<char,int> mp : sCharMap)
        {
            char skey {mp.first};
            int svalue {mp.second};
            if (tCharMap.count(skey) == 0)
                return false;

            if (svalue != tCharMap[skey])
                return false;
        }

        for (std::pair<char,int> mp : tCharMap)
        {
            char skey {mp.first};
            int svalue {mp.second};
            if (sCharMap.count(skey) == 0)
                return false;

            if (svalue != sCharMap[skey])
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sln;
    std::cout << std::boolalpha;

    // s = "anagram", t = "nagaram"
    std::string s1 {"anagram"};
    std::string t1 {"nagaram"};
    std::cout << sln.isAnagram(s1,t1) << "\n";
    
    // s = "rat", t = "car"
    std::string s2 {"rat"};
    std::string t2 {"car"};
    std::cout << sln.isAnagram(s2,t2) << "\n";
}