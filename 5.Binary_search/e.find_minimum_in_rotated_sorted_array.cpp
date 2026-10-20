#include <cstdlib>
#include <vector>
#include <iostream>

class Solution
{
public:
    int findMin(std::vector<int>& nums)
    {
        int len {static_cast<int>(nums.size())};
        int l {0};
        int r {len-1};

        while (l < r)
        {
            int mid {(l+r)/2};

            if (nums[mid] > nums[r])
            {
                l = mid+1;
            }
            else
            {
                r = mid; // Keep mid as a possible answer, thus avoid mid-1
            }
        }

        return nums[l];
    }
};

int main()
{
    Solution sln;
    std::vector<int> tst1 {3, 4, 5, 1, 2};
    std::cout << sln.findMin(tst1) << "\n";
    
    std::vector<int> tst2 {4, 5, 6, 7, 0, 1, 2};
    std::cout << sln.findMin(tst2) << "\n";

    std::vector<int> tst3 {1, 2, 3, 4, 5, 6, 7};
    std::cout << sln.findMin(tst3) << "\n";
    
    return EXIT_SUCCESS;
}