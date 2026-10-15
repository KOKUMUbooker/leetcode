#include <cstdlib>
#include <vector>
#include <iostream>

/*
Given an array of integers nums which is sorted in ascending order, and an integer target, 
write a function to search target in nums. If target exists, then return its index. 
Otherwise, return -1.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
*/

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
       int len {static_cast<int>(nums.size())};
       if (len == 1)
            return nums[0] == target ? 0 : -1;

       int low {0};
       int high {len-1};

       while (low <= high)
       {
            int mid {(low+high) / 2};
            if (nums[mid] == target)
                return mid;

            if (nums[mid] > target)
                high = mid - 1;
            else 
                low = mid + 1;
       }

       return -1;
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

    std::vector<int> tst1 {-1,0,3,5,9,12};
    std::cout << "Example 1 (target 9) : \n";
    printVector(tst1);
    std::cout << "Index : " << sln.search(tst1, 9) << "\n\n";

    std::vector<int> tst2 {-1,0,3,5,9,12};
    std::cout << "Example 2 (target 2) : \n";
    printVector(tst2);
    std::cout << "Index : " << sln.search(tst2, 2) << "\n\n";

    std::vector<int> tst3 {5};
    std::cout << "Example 3 (target 5) : \n";
    printVector(tst3);
    std::cout << "Index : " << sln.search(tst3, 5) << "\n\n";

    std::vector<int> tst4 {2,5};
    std::cout << "Example 4 (target 5) : \n";
    printVector(tst4);
    std::cout << "Index : " << sln.search(tst4, 5) << "\n";

    return EXIT_SUCCESS;
}