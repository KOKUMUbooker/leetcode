#include <vector>
#include <iostream>

/* This solution is implemented using brute force - O(n^2) , which is slow on large vectors*/
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> res {};
        int len {static_cast<int>(nums.size())};
        for (int i {0}; i < len; ++i)
        {
            int prod {1};
            for (int j {0}; j < len; ++j)
            {
                if (i == j)
                    continue;
                prod *= nums[j];
            }
            res.push_back(prod);
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