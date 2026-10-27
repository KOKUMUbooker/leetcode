#include <algorithm>
#include <climits>
#include <vector>
#include <iostream>
#include <iomanip>

/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

// General Idea :
//  -- The median is obtained by making partitions where the items on the left(l1 & l2 and back) should be less
//  -- the partition on the right (r1 & r2 and forward)
// [.. .. .. .. l1 , r1 .. ..] X
// [.. .. .. l2 , r2 .. .. ..] Y
// l1 <= r2
// l2 <= r1
class Solution {
public:
    double findMedianSortedArrays(
        std::vector<int>& nums1,
        std::vector<int>& nums2
    ) {
        std::vector<int>& smaller {
            nums1.size() <= nums2.size() ? nums1 : nums2
        };

        std::vector<int>& larger {
            nums1.size() <= nums2.size() ? nums2 : nums1
        };

        int totalLen {  static_cast<int>(nums1.size() + nums2.size()) };

        int low {0};
        int high {static_cast<int>(smaller.size())};

        while (low <= high) {
            int partX {low + (high - low) / 2};
            int partY {(totalLen + 1) / 2 - partX};

            int l1 { partX == 0 ? INT_MIN : smaller[partX - 1] };
            int r1 {  partX == smaller.size() ? INT_MAX : smaller[partX] };

            int l2 { partY == 0 ? INT_MIN : larger[partY - 1] };
            int r2 { partY == larger.size() ? INT_MAX : larger[partY] };

            if (l1 <= r2 && l2 <= r1) {
                if (totalLen % 2 == 0) {
                    return (
                        static_cast<double>(std::max(l1, l2)) +
                        std::min(r1, r2)
                    ) / 2.0;
                }

                return std::max(l1, l2);
            }

            if (l1 > r2) {
                high = partX - 1;
            } else {
                low = partX + 1;
            }
        }

        return 0.0;
    }
};

void printVector(const std::vector<int>& vec)
{
    int len {static_cast<int>(vec.size())};
    std::cout << "[";

    for (int i {0}; i < len; ++i)
    {
        std::cout << vec[i];

        if (i != len - 1)
            std::cout << ", ";
    }

    std::cout << "]\n";
}

int main()
{
    Solution solution {};

    // Example 1
    std::cout << "Example 1:\n";

    std::vector<int> nums1 {1, 3};
    std::vector<int> nums2 {2};

    std::cout << "nums1 = ";
    printVector(nums1);

    std::cout << "nums2 = ";
    printVector(nums2);

    double result1 {
        solution.findMedianSortedArrays(nums1, nums2)
    };

    std::cout << "Output: "
              << std::fixed << std::setprecision(5)
              << result1 << "\n";


    // Example 2
    std::cout << "\nExample 2:\n";

    std::vector<int> nums3 {1, 2};
    std::vector<int> nums4 {3, 4};

    std::cout << "nums1 = ";
    printVector(nums3);

    std::cout << "nums2 = ";
    printVector(nums4);

    double result2 {
        solution.findMedianSortedArrays(nums3, nums4)
    };

    std::cout << "Output: "
              << result2 << "\n";

    return EXIT_SUCCESS;
}