#include <cstdlib>
#include <vector>
#include <iostream>

class Solution {
public:
    int trap(std::vector<int>& height) {
        int prevHigh {0};
        int trapArea {0};
        int len {static_cast<int>(height.size())};
        for (int i {0}; i < len; ++i)
        {
            if (prevHigh == 0 || i == 0)
            {
                prevHigh = height[i];
                continue;
            }

            int nextHigh {0};
            int j {i+1};
            while (j < len)
            {
                nextHigh = std::max(nextHigh, height[j]);
                ++j;
            }

            if (nextHigh == 0)
                break;

            int waterHeight = std::min(prevHigh, nextHigh);
            // If current index is less that the least of the 2 high grounds, it can hold water
            if (height[i] < waterHeight) 
            {
                int areaAtCurPoint = (waterHeight - height[i]) * 1;
                trapArea += areaAtCurPoint;
            }
            
            // Update prevHigh
            prevHigh = std::max(height[i], prevHigh);
        }

        return trapArea;
    }
};

int main()
{
    Solution sln;
    std::vector<int> tst1 {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << sln.trap(tst1) << "\n";

    std::vector<int> tst2 {4,2,0,3,2,5};
    std::cout << sln.trap(tst2) << "\n";

    return EXIT_SUCCESS;
}