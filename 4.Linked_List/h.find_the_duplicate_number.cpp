#include <unordered_map>
#include <vector>
#include <iostream>

/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and using only constant extra space.

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3

Example 3:
Input: nums = [3,3,3,3,3]
Output: 3
*/

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        std::unordered_map<int,int> numMap {};
        for (int& n : nums)
        {
            if (numMap.count(n) > 0)
                return n;
            else 
                numMap.try_emplace(n,1);
        }

        return 0;
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
    Solution solution;


    // Example 1
    // Input:  [1,3,4,2,2]
    // Output: 2

    std::vector<int> nums1 {1, 3, 4, 2, 2};

    std::cout << "Example 1\n";

    std::cout << "Input:  ";
    printVector(nums1);

    std::cout << "Output: "
              << solution.findDuplicate(nums1)
              << "\n\n";


    // Example 2
    // Input:  [3,1,3,4,2]
    // Output: 3

    std::vector<int> nums2 {3, 1, 3, 4, 2};

    std::cout << "Example 2\n";

    std::cout << "Input:  ";
    printVector(nums2);

    std::cout << "Output: "
              << solution.findDuplicate(nums2)
              << "\n\n";


    // Example 3
    // Input:  [3,3,3,3,3]
    // Output: 3

    std::vector<int> nums3 {3, 3, 3, 3, 3};

    std::cout << "Example 3\n";

    std::cout << "Input:  ";
    printVector(nums3);

    std::cout << "Output: "
              << solution.findDuplicate(nums3)
              << "\n";


    return EXIT_SUCCESS;
}