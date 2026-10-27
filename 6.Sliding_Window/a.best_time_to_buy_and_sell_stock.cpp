#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>


class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int len {static_cast<int>(prices.size())};

        if (len < 2)
            return 0;

        int minPrice {prices[0]};
        int max {0};

        for (int i {1}; i < len; ++i)
        {
            int profit {prices[i] - minPrice};
            max = std::max(max, profit);

            minPrice = std::min(minPrice, prices[i]);
        }

        return max;
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
    Solution sln;
    std::vector<int> tst1 {7,1,5,3,6,4};
    printVector(tst1);
    std::cout << "Output : " << sln.maxProfit(tst1) << "\n";
    
    std::vector<int> tst2 {7,6,4,3,1};
    printVector(tst2);
    std::cout << "Output : " << sln.maxProfit(tst2) << "\n";

    return EXIT_SUCCESS;
}