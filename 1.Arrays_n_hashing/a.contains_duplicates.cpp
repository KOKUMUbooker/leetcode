#include <iostream>
#include <vector>
#include <unordered_map>

/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:
Input: nums = [1,2,3,1]
Output: true

Explanation:
The element 1 occurs at the indices 0 and 3.

Example 2:
Input: nums = [1,2,3,4]
Output: false

Explanation:
All elements are distinct.

Example 3:
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_map<int, int> existMap{};
        for (const int num : nums) {
            if (existMap.count(num) > 0)
                return true;
            else
                existMap.try_emplace(num, 1);
        }

        return false;
    }
};

int main()
{
    Solution sln;
    std::cout << std::boolalpha;

    std::vector<int> test1 {1,2,3,4};
    std::cout << sln.containsDuplicate(test1) << "\n";

    std::vector<int> test2 {1,1,1,3,3,4,3,2,4,2};
    std::cout << sln.containsDuplicate(test2) << "\n";

    return EXIT_SUCCESS;
}