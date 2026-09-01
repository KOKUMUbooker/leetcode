#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
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

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> strs) {
        std::vector<std::vector<std::string>> res {};
        std::unordered_map<std::string,std::vector<std::string>> mp {};
        
        for (std::string& s : strs)
        {
            std::string sorted {s};
            std::sort(sorted.begin(),sorted.end());
            if (mp.count(sorted) > 0)
                mp[sorted].push_back(s);
            else
                mp.try_emplace(sorted, std::vector<std::string>{s});
        }

        for (std::pair<std::string,std::vector<std::string>> pairVal : mp)
            res.push_back(pairVal.second);
       
        return res;
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

