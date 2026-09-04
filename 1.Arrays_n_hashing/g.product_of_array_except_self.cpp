#include <vector>
#include <iostream>

/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int len {static_cast<int>(nums.size())};

        // Calculate prev product summation for each digit before it & store it in its index
        std::vector<int> prefix (len,1);
        int prod1 {1};
        for (int i {1}; i < len; ++i)
        {
            prod1 = prod1 * nums[i-1];
            prefix[i] = prod1;
        }

        // Calculate prev product summation for each digit after it & store it in its index
        std::vector<int> postfix (len,1);
        int prod2 {1};
        for (int i {len-2}; i >= 0; --i)
        {
            prod2 = prod2 * nums[i+1];
            postfix[i] = prod2;
        }

        // Having calculated the prev and after product summation for each index, we can calculate answer for each index
        std::vector<int> res (len,1);
        for (int i {0}; i < len; ++i)
        {
            res[i] = postfix[i] * prefix[i];
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
    std::vector<int> tst1 {1,2,3,4};
    printVector(sln.productExceptSelf(tst1));

    std::vector<int> tst2 {-1,1,0,-3,3};
    printVector(sln.productExceptSelf(tst2));

    return EXIT_SUCCESS;
}