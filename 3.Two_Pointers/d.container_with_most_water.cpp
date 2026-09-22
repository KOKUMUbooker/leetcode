#include <vector>
#include <iostream>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int len {static_cast<int>(height.size())};
        int l {0};
        int r {len-1};
        int maxArea {0};

        while (l < r)
        {
            int h {std::min(height[l],height[r])};
            int w {r-l};
            maxArea = std::max(h*w, maxArea);

            if (height[r] > height[l])
                ++l;
            else if (height[l] > height[r])
                --r;
            else 
                ++l;
        }
        
        return maxArea;
    }
};

int main()
{
    Solution sln;
    std::vector<int> tst1 {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << sln.maxArea(tst1) << "\n";

    std::vector<int> tst2 {1, 1};
    std::cout << sln.maxArea(tst2) << "\n";

    std::vector<int> tst3 {8, 7, 2, 1};
    std::cout << sln.maxArea(tst3) << "\n";

    return EXIT_SUCCESS;
}