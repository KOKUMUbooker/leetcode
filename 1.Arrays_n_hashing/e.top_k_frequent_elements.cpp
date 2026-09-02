#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Example 3:
Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: [1,2]
*/

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> mp {};
        for (int& n : nums)
        {
            if (mp.count(n) == 0)
                mp.try_emplace(n,1);
            else
                ++mp[n];
        }

        std::vector<std::pair<int,int>> freq (mp.begin(), mp.end());

        // Sort in descending order based on the values in the key-value pairs
        std::sort(freq.begin(), freq.end(), [](const auto& a, const auto& b){
            return a.second > b.second;
        });

        std::vector<int> res {};
        for (int i {0}; i < k; ++i)
            res.push_back(freq[i].first);

        return res;
    }
};

void printVector(const std::vector<int>& vec)
{
    int len {static_cast<int>(vec.size())};
    std::cout << "[";
    for (int i {0}; i < len; ++i)
    {
        std::cout << vec[i];
        if (i != (len-1))
            std::cout << ", ";
    }
    std::cout << "]\n";
}

int main()
{
    Solution sln;
    std::vector<int> tst1 {1,1,1,2,2,3};
    printVector(sln.topKFrequent(tst1,2));

    std::vector<int> tst2 {1};
    printVector(sln.topKFrequent(tst2,1));

    std::vector<int> tst3 {1,2,1,2,1,2,3,1,3,2};
    printVector(sln.topKFrequent(tst3,2));

    return EXIT_SUCCESS;
}