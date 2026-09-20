#include <cstdlib>
#include <vector>
#include <iostream>

/*
You are given a 1-indexed array of integers numbers that is already sorted in non-decreasing order.
Find two numbers such that they add up to a specific target number. 
Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
Return the indices of the two numbers index1 and index2 as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space.

Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
*/

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int len {static_cast<int>(numbers.size())};
        int ptr1 {0};
        int ptr2 {len-1};

        while (ptr1 < ptr2)
        {
            int sum {numbers[ptr1] + numbers[ptr2]};
            if (numbers[ptr1] + numbers[ptr2] == target)
                break;
            else if (numbers[ptr1] + numbers[ptr2] > target)
                --ptr2;
            else
                ++ptr1;
        }
        
        return std::vector<int>{ptr1+1, ptr2+1};
    }
};

void printVector(std::vector<int> vec)
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
    printVector(sln.twoSum(tst1, 9));

    std::vector<int> tst2 {2,3,4};
    printVector(sln.twoSum(tst2, 6));

    std::vector<int> tst3 {-1,0};
    printVector(sln.twoSum(tst3, -1));

    return EXIT_SUCCESS;
}