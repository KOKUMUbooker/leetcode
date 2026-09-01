#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

Example 1:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:
There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

Example 2:
Input: strs = [""]
Output: [[""]]

Example 3:
Input: strs = ["a"]
Output: [["a"]]
*/

/* This code works but is SLOW on massive vectors - My first attempt */
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        int len {static_cast<int>(strs.size())};
        std::vector<std::vector<std::string>> res {};
        std::unordered_map<int,bool> alreadyAdded {};

        for (int i {0}; i < len; ++i)
        {
            std::vector<std::string> curRes {strs[i]};
            for (int j {0}; j < len; ++j)
            {
                if (i == j)
                    continue;
                if (alreadyAdded.count(j) > 0)
                    continue;

                if (ValidAnagramHelper(strs[i], strs[j]) && alreadyAdded.count(j) == 0)
                {
                    alreadyAdded.try_emplace(j,true);
                    curRes.push_back(strs[j]);
                }
            }

            if (alreadyAdded.count(i) == 0)
                res.push_back(curRes);
        }

        return res;
    }

    bool ValidAnagramHelper(const std::string& s1, const std::string& s2)
    {
        if (s1.size() != s2.size())
            return false;

        if (s1.size() == 0 && s2.size() == 0)
            return true;

        int len {static_cast<int>(s1.size())};
        std::unordered_map<char,int> s1Map {};
        std::unordered_map<char,int> s2Map {};
        for (int i {0}; i < len; ++i)
        {
            if (s1Map.count(s1[i]) > 0)
                ++s1Map[s1[i]];
            else
                s1Map.try_emplace(s1[i],1);

            if (s2Map.count(s2[i]) > 0)
                ++s2Map[s2[i]];
            else
                s2Map.try_emplace(s2[i],1);
        }

        for (std::pair<char,int> mp1  : s1Map)
        {
            char s1Char {mp1.first};
            if (s2Map.count(s1Char) == 0)
                return false;
            
            if (s1Map[s1Char] != s2Map[s1Char])
                return false;
        }

        for (std::pair<char,int> mp2  : s2Map)
        {
            char s2Char {mp2.first};
            if (s1Map.count(s2Char) == 0)
                return false;
            
            if (s1Map[s2Char] != s2Map[s2Char])
                return false;
        }

        return true;
    }
};

void Print2DVector(const std::vector<std::vector<std::string>>& vec)
{
    std::cout << "[";
     int outLen {static_cast<int>(vec.size())};

    for (int i {0}; i < outLen; ++i)
    {
        int inLen {static_cast<int>(vec[i].size())};
        for (int j {0}; j < inLen; ++j)
        {
            std::cout << '\"' << vec[i][j] << '\"';
            if (j != inLen-1)
                std::cout << ",";
        }

        if (i != outLen-1)
            std::cout << ",";
    }
    std::cout << "]\n";
}

int main()
{
    Solution sln;
    std::vector<std::string> tst1 {"eat","tea","tan","ate","nat","bat"};
    Print2DVector(sln.groupAnagrams(tst1));

    std::vector<std::string> tst2 {""};
    Print2DVector(sln.groupAnagrams(tst2));

    std::vector<std::string> tst3 {"a"};
    Print2DVector(sln.groupAnagrams(tst3));

    std::vector<std::string> tst4 {"",""};
    Print2DVector(sln.groupAnagrams(tst4));

    return EXIT_SUCCESS;
}