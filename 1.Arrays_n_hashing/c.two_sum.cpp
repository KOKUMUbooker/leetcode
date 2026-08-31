#include <vector>
#include <iostream>

/*
You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
*/

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int len {static_cast<int>(nums.size())};
        std::vector<int> res {};
        for (int i {0}; i < len; ++i)
        {
            for (int j {0}; j < len; ++j)
            {
                if (i == j) 
                    continue;
                if (nums[i] + nums[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }

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

    std::vector<int> tst1 {2,7,11,15};
    printVector(sln.twoSum(tst1,9));

    std::vector<int> tst2 {3,2,4};
    printVector(sln.twoSum(tst2,6));

    std::vector<int> tst3 {3,3};
    printVector(sln.twoSum(tst3,6));

    return EXIT_SUCCESS;
}