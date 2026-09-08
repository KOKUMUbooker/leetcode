#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:
Input: nums = [1,0,1,2]
Output: 3
*/


void printVector(const std::vector<int>& vec);

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        int len {static_cast<int>(nums.size())};
        if (len <= 1)
            return len;

        std::vector<int> sorted (nums.begin(),nums.end());
        std::sort(sorted.begin(), sorted.end()); // Sort in ascending order
        // printVector(sorted);

        int prev {sorted[0]};
        std::vector<std::vector<int>> groups {
            {sorted[0]}
        };
        for (int i {0}; i < len; ++i)
        {
            if (prev+1 == sorted[i])
                groups[groups.size()-1].push_back(sorted[i]);
            else if (sorted[i] == prev)
                continue;
            else 
                groups.push_back({sorted[i]});

            prev = sorted[i];
        }

        std::size_t largest {groups[0].size()};
        for (std::vector<int> group : groups)
        {
            if (group.size() > largest)
                largest = group.size();
        }

        return largest;
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
    std::vector<int> tst1 {100,4,200,1,3,2};
    std::cout << sln.longestConsecutive(tst1) << "\n";

    std::vector<int> tst2 {0,3,7,2,5,8,4,6,0,1};
    std::cout << sln.longestConsecutive(tst2) << "\n";

    std::vector<int> tst3 {1,0,1,2};
    std::cout << sln.longestConsecutive(tst3) << "\n";

    std::vector<int> tst4 {1,2,6,7,8};
    std::cout << sln.longestConsecutive(tst4) << "\n";

    return EXIT_SUCCESS;
}