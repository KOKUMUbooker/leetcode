#include <cstdlib>
#include <vector>
#include <iostream>

/*
You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Example 1:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
*/

class Solution {
private:
    bool binarySearch(std::vector<int>& nums, int target)
    {
        int len {static_cast<int>(nums.size())};
        if (len == 1)
            return nums[0] == target;

        int low {0};
        int high {len-1};
        while (low <= high)
        {
            int mid {(low+high) / 2};
            if (nums[mid] == target)
                return true;

            if (nums[mid] < target)
                low = mid + 1;
            else 
                high = mid - 1;
        }

        return false;
    }
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int len {static_cast<int>(matrix.size())};
        if (len == 1)
            return binarySearch(matrix[0], target);
        
        int low {0};
        int high {len-1};
        while (low <= high)
        {
            int mid {(low+high) / 2};
            int lenMid {static_cast<int>(matrix[mid].size())};
            if (matrix[mid][0] <= target && matrix[mid][lenMid-1] >= target)
                return binarySearch(matrix[mid], target);

            if (target < matrix[mid][0])
                high = mid - 1;
            else 
                low = mid + 1;
        }

        return false;
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

void printMatrix(const std::vector<std::vector<int>>& matrix)
{
    for (const std::vector<int>& row : matrix)
        printVector(row);
}

int main()
{
    Solution solution {};

    // Example 1
    std::cout << "Example 1:\n";

    std::vector<std::vector<int>> matrix1 {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target1 {3};

    std::cout << "Matrix:\n";
    printMatrix(matrix1);

    std::cout << "Target: " << target1 << "\n";

    bool result1 {solution.searchMatrix(matrix1, target1)};

    std::cout << "Output: "
              << (result1 ? "true" : "false")
              << "\n";


    // Example 2
    std::cout << "\nExample 2:\n";

    std::vector<std::vector<int>> matrix2 {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target2 {13};

    std::cout << "Matrix:\n";
    printMatrix(matrix2);

    std::cout << "Target: " << target2 << "\n";

    bool result2 {solution.searchMatrix(matrix2, target2)};

    std::cout << "Output: "
              << (result2 ? "true" : "false")
              << "\n";

    return EXIT_SUCCESS;
}