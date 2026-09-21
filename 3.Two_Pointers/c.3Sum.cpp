#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
*/

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int len {static_cast<int>(nums.size())};
        std::vector<std::vector<int>> res;

        for (int i {0}; i < len-2; ++i)
        { 
            // Terminate early as we can't get sum of 0 with starting point as positive value
            if (nums[i] > 0) 
                break;

            // To avoid ending up with duplicates from starting point
            if (i > 0 && nums[i] == nums[i-1])
                continue;

            int j {i+1};
            int k {len-1};
            int target {-nums[i]};

            while (j < k)
            {
                if (nums[j] + nums[k] > target)
                    --k;
                else if (nums[j] + nums[k] < target)
                    ++j;
                else
                {
                    res.push_back(std::vector<int>{nums[i], nums[j], nums[k]});
                    ++j;
                    while (nums[j] == nums[j-1] && j < k) // Avoid duplicates from inner left pointer
                        ++j;
                }
            }
        }

        return res;
    }
};

void Print2DVector(const std::vector<std::vector<int>>& vec)
{
    std::cout << "[";
    int outLen {static_cast<int>(vec.size())};

    for (int i {0}; i < outLen; ++i)
    {
        int inLen {static_cast<int>(vec[i].size())};
        std::cout << " [";
        for (int j {0}; j < inLen; ++j)
        {
            std::cout << vec[i][j] ;
            if (j != inLen-1)
                std::cout << ",";
        }

        if (i != outLen-1)
            std::cout << ",";

        std::cout << "] ";
    }
    std::cout << "]\n";
}

int main()
{
    Solution sln;
    std::vector<int> tst1 {-1,0,1,2,-1,-4};
    Print2DVector(sln.threeSum(tst1));
    
    std::vector<int> tst2 {0,1,1};
    Print2DVector(sln.threeSum(tst2));

    std::vector<int> tst3 {0,0,0};
    Print2DVector(sln.threeSum(tst3));

    std::vector<int> tst4 {0,0,0,0};
    Print2DVector(sln.threeSum(tst4));

    return EXIT_SUCCESS;
}